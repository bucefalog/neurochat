Compilation instructions:

1) Compile VCam: 
  1.1) Open neurochat.sln with visual studio 2017 or later
  1.2) Build the project VCam
    1.2.1) Make sure the solution is configured for release x64 version
    1.2.2) The project uses nuggets to install OpenCV dependencies, if the selected nugget does not work for your system, consider using another nugget or manually installing and linking OpenCV to the project
    1.2.3) Change line 307 in file "Camera.cpp", switch capture device from 2, to your camera value (most likely 0)
2) Compile BCI Classifier2
  2.1) Install Qt
  2.2) Open PROJECT_FOLDER/BCIClassifier2/BCIClassifier2.pro
  2.3) Compile the project
3) If you want to use manual filter selection, compile NeuroChatGUI
  3.1) Open PROJECT_FOLDER/NeuroChatGUI/NeuroChatGUI.pro
  3.2) Compile the project
  

  
Usage instructions:
  1) Before using the virtual camera for the first time, you need to register the camera. To do so, in an elevated command prompt execute the following commands:
        cd PROJECT_FOLDER/Bin/x64/Release/
        regsvr32.exe VCamx64.dll
   A prompt should appear stating that the filter was successfully registered
  2) Open the filter selection application (either manual or automatic selection)
    2.1) For manual selection:
      2.1.1) Navigate to: PROJECT_FOLDER/build-NeuroChatGUI-Desktop_Qt_5_11_2_MSVC2017_64bit2-Release/release
      2.1.2) Open NeuroChatGUI.exe
      2.1.3) To choose a filter just click in its respective image.
    2.2) For automatic selection using BCI:
      2.2.1) Open the Emotiv's cortex application and log into your account
      2.2.2) Navigate to: PROJECT_FOLDER/build-BCIClassifier2-Desktop_Qt_5_11_2_MSVC2017_64bit2-Release/release/
      2.2.3) Open BCIClassifier2.exe
      2.2.4) follow the console prompts, you will be required to log into your emotiv's account. The user and password must match the same one entered for Emotiv's Cortex
  3) Open any 64 bit video chat application that uses Directshow filters (tested with hangouts on 64 bit navigator)
    3.1) In the applications's options, choose to use VCam as the video input source