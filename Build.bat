@echo off
echo Building Aura...

call "D:\Programs\UE_5.7\Engine\Build\BatchFiles\Build.bat" AuraEditor Win64 Development -Project="E:\Unreal Projects\C++ Projects\Aura_GitHub\Aura.uproject"

if %errorlevel% neq 0 (
    echo Build FAILED. Check errors above.
    pause
    exit /b %errorlevel%
)

echo Build succeeded! Launching editor...
start "" "D:\Programs\UE_5.7\Engine\Binaries\Win64\UnrealEditor.exe" "E:\Unreal Projects\C++ Projects\Aura_GitHub\Aura.uproject"