# opencv-examples-with-cpp

# Opencv Settings
### IDE: Microsoft Visual Studio C++ 2010 Express
### Opencv Version: 2.4.10
----
`Project -> Properties -> Configuration Properties -> VC++ Directories -> Include Directories:`
```
C:\Program Files (x86)\opencv\build\include
C:\Program Files (x86)\opencv\build\include\opencv
C:\Program Files (x86)\opencv\build\include\opencv2
```
----
`Project -> Properties -> Configuration Properties -> VC++ Directories -> Library Directories:`
```
C:\Program Files (x86)\opencv\build\x86\vc10\lib
```
----
`Project -> Properties -> Configuration Properties -> Linker -> Input -> Additional Dependencies:`
```
opencv_core2410d.lib
opencv_highgui2410d.lib
opencv_imgproc2410d.lib
```
----
`Project -> Properties -> Configuration Properties -> Debugging -> Environment:`
```
PATH=C:\Program Files (x86)\opencv\build\x86\vc10\bin;%PATH%
```
----
 