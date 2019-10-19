/*
  Copyright (C) 2018 Rory Walsh

  You should have received a copy of the GNU Lesser General Public
  License along with Csound; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
  02110-1301 USA
*/

#include <plugin.h>
#include <vector>

// expseg type opcode with trigger mechanism
struct TrigExpseg : csnd::Plugin<1, 64>
{
    int init()
    {
        int argCnt = 1;
        samplingRate = csound->sr();
        playEnv = 0;
        counter = 0;
        outargs[0] = inargs[1];
        segment = 0;
        outValue = inargs[1];

        while (argCnt < in_count())
        {
            if (argCnt % 2 == 0)
                durations.push_back (inargs[argCnt]*samplingRate);
            else
            {
                if (inargs[argCnt] <= 0.0)
                {
                    csound->message ("iVal is 0");
                    return NOTOK;
                }

                values.push_back (inargs[argCnt]);
            }

            argCnt++;
        }

        incr = pow (values[1] / values[0], 1 / (durations[0]));

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
                incr = pow (values[segment + 1] / values[segment], 1 / (durations[segment]));
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

    int samplingRate, playEnv, counter, segment;
    MYFLT outValue, incr;
    std::vector<MYFLT> values;
    std::vector<MYFLT> durations;
};

#include <modload.h>

/* The mult opcode is overloaded for
   a, k, and i inputs. For these cases, it is
   recommended to append an identifier extension .
   to the name for debugging purposes (not strictly required).
   For the user, the extension is not used and all
   overloads are called "mult"
*/
void csnd::on_load (Csound* csound)
{
    csnd::plugin<TrigExpseg> (csound, "trigexpseg.aa", "a", "km", csnd::thread::ia);
    csnd::plugin<TrigExpseg> (csound, "trigexpseg.kk", "k", "km", csnd::thread::ik);
}

