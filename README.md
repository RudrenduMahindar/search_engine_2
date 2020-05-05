# Final search engine backend ==>> search_engine_2
Search engine version 2 uses a map(keyword,root_of_BST). The complete overview of the system is available [here](https://github.com/anujp10/qt_search_engine/blob/master/User_guide.pdf). 
This c++ search engine was created after the search_engine_1 in my repo. 
This is the final c++ backend portion of the [mini search engine](https://github.com/anujp10/qt_search_engine) submitted as a [course project](https://github.com/ourarash/EE599_SP2020_Final_Project) of [EE599:Computing and Software for Systems Engineers](https://web-app.usc.edu/soc/syllabus/20201/30586.pdf) under the guidance of [Professor Arash Saifhashemi](https://www.linkedin.com/in/ourarash/). 
Please refer to this [link](https://github.com/anujp10/qt_search_engine/blob/master/README.md) for description of the project and features, and for setting up the environment and building the project refer to this [guide](https://github.com/anujp10/qt_search_engine/blob/master/User_guide.pdf).
The c++ code of this repo was integrated with Qt for the complete system and the final project is available [here](https://github.com/anujp10/qt_search_engine). 

# Build instructions
This c++ project prints the search results in your console screen. This project was developed on Visual Studio Code 1.43.2 with Bazel 3.0.0 on a 64-bit Ubuntu 16.04 inside a virtual machine in windows 10.
Try out this c++ search engine by installing Bazel and Visual Studio Code (preferably inside Ubuntu).
For building C++ files, you can install Bazel using this [link](https://docs.bazel.build/versions/master/install.html).
After the installation of visual studio code and bazel is complete follow the steps below:
## 1. Clone this repo:
git clone https://github.com/RudrenduMahindar/search_engine_2.git 

## 2. Build and run this project in Visual Studio Code
### Open Visual Studio Code
### Click on File->Open Folder, select the folder of search_engine_2 and open it
### Click on Terminal->New Terminal
After the terminal opens, type:
### bazel run src/main:main





