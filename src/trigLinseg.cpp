/*
  Copyright (C) 2018 Rory Walsh

  You should have received a copy of the GNU Lesser General Public
  License along with Csound; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
  02110-1301 USA
*/

#include <plugin.h>
#include <vector>
#include <numeric>
#include <modload.h>


// linseg type opcode with trigger mechanism
struct TrigLinseg : csnd::Plugin<1, 64>
{
    int init()
    {
        int iCnt = 1;
        totalLength = 0;
        samplingRate = csound->sr();
        playEnv = 0;
        counter = 0;
        outargs[0] = inargs[1];
        segment = 0;
        outValue = 0;

        while (iCnt < in_count())
        {
            if (iCnt % 2 == 0)
                durations.push_back (inargs[iCnt]*samplingRate);
            else
                values.push_back (inargs[iCnt]);

            iCnt++;
        }

        incr = (values[1] - values[0]) / durations[0];
        totalLength = std::accumulate (durations.begin(), durations.end(), 0);
        csound->message (std::to_string (totalLength));

        return OK;
    }

    int kperf()
    {
        outargs[0] = envGenerator (this, nsmps);
        return OK;
    }


    int aperf()
    {
        for (int i = offset; i < nsmps; i++)
            outargs (0)[i] = envGenerator (this, 1);

        return OK;
    }

    MYFLT envGenerator (Plugin* opcodeData, int sampIncr)
    {
        // trigger envelope
        if (opcodeData->inargs[0] == 1)
            playEnv = 1;

        if (playEnv == 1 && segment <= durations.size())
        {
            if (counter < durations[segment])
            {
                outValue *= incr;
                counter += sampIncr;
            }
            else
            {
                segment++;
                counter = 0;
                incr = (values[segment + 1] - values[segment]) / durations[0];
            }
        }
        else
        {
            playEnv = 0;
            counter = 0;
            segment = 0;
            outValue = values[values.size() - 1];
        }

        return outValue;
    }

    int samplingRate, playEnv, counter, totalLength, segment;
    MYFLT outValue, incr;
    std::vector<MYFLT> values;
    std::vector<MYFLT> durations;
};


void csnd::on_load (Csound* csound)
{
    csnd::plugin<TrigLinseg> (csound, "trigLinseg.aa", "a", "km", csnd::thread::ia);
    csnd::plugin<TrigLinseg> (csound, "trigLinseg.kk", "k", "km", csnd::thread::ik);
}

