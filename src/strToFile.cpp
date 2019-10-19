/*
    Copyright (C) 2018 Rory Walsh

    You should have received a copy of the GNU Lesser General Public
    License along with Csound; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
    02110-1301 USA
 */

#include <plugin.h>
#include <string>
#include <vector>
#include <modload.h>
#include <fstream>


//==========================================================
//removes a number of occurrences of one string from another
//==========================================================
struct StrToFile : csnd::Plugin<0, 3>
{
    int init()
    {
        // DIR *dir = opendir(".");
        // if (dir) {
        //   struct dirent *ent;
        //   while ((ent = readdir(dir)) != NULL) {
        //     csound->message(ent->d_dir);
        //   }
        // }

        if (in_count() < 2)
        {
            csound->message ("You did not pass have enough arguments to strtofile\n");
            return NOTOK;
        }

        char* fileName = inargs.str_data (0).data;
        char* inString = inargs.str_data (1).data;
        int mode = inargs[2];

        std::ofstream fileStream;

        if (mode == 1)
        {
            fileStream.open (fileName, std::ios::in | std::ios::app);
        }
        else
            fileStream.open (fileName, std::ios::in | std::ios::trunc);

        fileStream << inString;

        if (!fileStream.is_open())
        {
            csound->message ("*** strtofile could not open file for writing ***");
            return NOTOK;
        }

        fileStream.close();

        return OK;
    }
};

void csnd::on_load (Csound* csound)
{
    csnd::plugin<StrToFile> (csound, "strtofile.ii", "", "SSi", csnd::thread::i);
}

