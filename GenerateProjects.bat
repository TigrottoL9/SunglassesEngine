call premake\premake5.exe vs2022 &call .\vcpkg-master\bootstrap-vcpkg.bat &call .\vcpkg-master\vcpkg.exe integrate install & call .\vcpkg-master\vcpkg.exe install raylib:x64-windows &start "" ".\SunglassesEngine.sln"