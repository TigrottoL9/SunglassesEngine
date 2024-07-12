function download_progress(total, current)
    local ratio = current / total;
    ratio = math.min(math.max(ratio, 0), 1);
    local percent = math.floor(ratio * 100);
    print("Download progress (" .. percent .. "%/100%)")
end

function check_raylib()
    if(os.isdir("raylib") == false and os.isdir("raylib-master") == false) then
        if(not os.isfile("raylib-master.zip")) then
            print("Raylib not found, downloading from github")
            local result_str, response_code = http.download("https://github.com/raysan5/raylib/archive/refs/heads/master.zip", "raylib-master.zip", {
                progress = download_progress,
                headers = { "From: Premake", "Referer: Premake" }
            })
        end
        print("Unzipping to " ..  os.getcwd())
        zip.extract("raylib-master.zip", os.getcwd())
        os.remove("raylib-master.zip")
    end
end

function check_vcpkg()
    if(os.isdir("vcpkg") == false and os.isdir("vcpkg-master") == false) then
        if(not os.isfile("vcpkg-master.zip")) then
            print("vcpkg not found, downloading from github")
            local result_str, response_code = http.download("https://github.com/microsoft/vcpkg/archive/refs/heads/master.zip", "vcpkg-master.zip", {
                progress = download_progress,
                headers = { "From: Premake", "Referer: Premake" }
            })
        end
        print("Unzipping to " ..  os.getcwd())
        zip.extract("vcpkg-master.zip", os.getcwd())
        os.remove("vcpkg-master.zip")
    end
end

workspace "SunglassesEngine"
	architecture "x64"
	
	configurations 
	{ 
		"Debug",
		"Release",
		"Dist",
	}
	
	startproject "SunglassesEditor"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

newoption
{
    trigger = "graphics",
    value = "OPENGL_VERSION",
    description = "version of OpenGL to build raylib against",
    allowed = {
        { "opengl11", "OpenGL 1.1"},
        { "opengl21", "OpenGL 2.1"},
        { "opengl33", "OpenGL 3.3"},
        { "opengl43", "OpenGL 4.3"},
        { "opengles2", "OpenGLES 2.0"},
        { "opengles3", "OpenGLES 3.0"}
    },
    default = "opengl43"
}

project "SunglassesEngine"
	location "SunglassesEngine"
	kind "StaticLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}
	
	includedirs
	{
		
	}
	
	links 
	{
		
	}
	
	filter "system:windows"
		cppdialect "c++20"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			
		}
	
	prebuildcommands
	{
		"{MKDIR} ../bin/" .. outputdir .. "/SunglassesEditor/%{cfg.buildtarget.name}"
	}
	
	postbuildcommands
	{
		("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SunglassesEditor/%{cfg.buildtarget.name}")
	}
	
	filter "configurations:Debug"
		defines
		{
			
		}
		symbols "On"
	
	filter "configurations:Release"
		defines
		{
			
		}
		optimize "On"
		
	filter "configurations:Dist"
		defines
		{
			
		}
		optimize "On"
	

project "SunglassesEditor"
	location "SunglassesEditor"
	kind "ConsoleApp"
	language "C++"
	dependson { "SunglassesEngine"}
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}
	
	includedirs
	{
		"SunglassesEngine/src"
	}
	
	links 
	{
		"SunglassesEngine"
	}
	
	
	filter "system:windows"
		cppdialect "c++20"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			
		}
	
	filter "configurations:Debug"
		defines
		{
			
		}
		symbols "On"
	
	filter "configurations:Release"
		defines
		{
			
		}
		optimize "On"
		
	filter "configurations:Dist"
		defines
		{
			
		}
		optimize "On"
		
-- download raylib
check_raylib();

-- download vcpkg
check_vcpkg();


include ("premake5-raylib.lua")