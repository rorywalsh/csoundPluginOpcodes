echo "AGENT_WORKFOLDER is $AGENT_WORKFOLDER"
echo "AGENT_WORKFOLDER contents:"
ls -1 $AGENT_WORKFOLDER
echo "AGENT_BUILDDIRECTORY is $AGENT_BUILDDIRECTORY"
echo "AGENT_BUILDDIRECTORY contents:"
ls -1 $AGENT_BUILDDIRECTORY
echo "SYSTEM_DEFAULTWORKINGDIRECTORY is $SYSTEM_DEFAULTWORKINGDIRECTORY"
echo "SYSTEM_DEFAULTWORKINGDIRECTORY contents:"
ls -1 $SYSTEM_DEFAULTWORKINGDIRECTORY
echo "BUILD_ARTIFACTSTAGINGDIRECTORY is $BUILD_ARTIFACTSTAGINGDIRECTORY"
echo "BUILD_ARTIFACTSTAGINGDIRECTORY contents:"
ls -1 $BUILD_ARTIFACTSTAGINGDIRECTORY

sudo apt-get build-dep csound
sudo apt-get update --fix-missing
sudo apt-get update -qq
sudo apt-get install libsndfile1
git clone https://github.com/csound/csound.git
cd csound
mkdir build
cd build
cmake ..
make -j4
sudo make install
sudo ldconfig

#return to main working dir after installing Csound
cd $SYSTEM_DEFAULTWORKINGDIRECTORY

ls

mkdir build
cd build
cmake ..
make
ls
mkdir $BUILD_ARTIFACTSTAGINGDIRECTORY/Linux
cp *.so $BUILD_ARTIFACTSTAGINGDIRECTORY/Linux
