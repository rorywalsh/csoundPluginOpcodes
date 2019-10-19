/*
 Copyright (C) 2018 Rory Walsh

 You should have received a copy of the GNU Lesser General Public
 License along with Csound; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 02110-1301 USA
 */

#include <plugin.h>
#include <string>
#include <modload.h>
#include <fstream>
#include "json.hpp"

#define STRING 19
#define CONTROL 17


using json = nlohmann::json;
struct channelPresetSave : csnd::Plugin<1, 1>
{
    int init()
    {
        json j;

        controlChannelInfo_s* csoundChanList;
        int numberOfChannels = csound->get_csound()->ListChannels (csound->get_csound(), &csoundChanList);

        for (int i = 0; i < numberOfChannels; i++ )
        {
            const float min = csoundChanList[i].hints.min;
            const float max = (csoundChanList[i].hints.max ==  0 ? 1 : csoundChanList[i].hints.max);
            const float defaultValue = csoundChanList[i].hints.dflt;
            std::string name;

            MYFLT* value;
            char* chString;

            if (csound->get_csound()->GetChannelPtr (csound->get_csound(), &value, csoundChanList[i].name,
                    CSOUND_CONTROL_CHANNEL | CSOUND_OUTPUT_CHANNEL) == CSOUND_SUCCESS)
            {
                csound->message (std::string ("Control channel: " + std::string (csoundChanList[i].name)) + " - " + std::to_string (*value));
                j[csoundChanList[i].name] = *value;
            }

            if (csound->get_csound()->GetChannelPtr (csound->get_csound(), &value, csoundChanList[i].name,
                    CSOUND_STRING_CHANNEL | CSOUND_OUTPUT_CHANNEL) == CSOUND_SUCCESS)
            {

                if (value != NULL)
                {
                    chString = ((STRINGDAT*)value)->data;
                    csound->message (std::string ("String channel: " + std::string (csoundChanList[i].name)) + " - " + std::string (chString));
                    j[csoundChanList[i].name] = std::string (chString);
                }
            }




        }

        csound->message(j.dump());
        return OK;
    }

};


struct channelPresetOpen : csnd::Plugin<1, 1>
{
    int init()
    {


        return OK;
    }

};



void csnd::on_load (Csound* csound)
{
    csnd::plugin<channelPresetSave> (csound, "channelStateSave.i", "i", "S", csnd::thread::i);
    csnd::plugin<channelPresetOpen> (csound, "channelStateRecall.i", "i", "S", csnd::thread::i);

}