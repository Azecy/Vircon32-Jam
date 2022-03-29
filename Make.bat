@echo off
REM create obj and bin folders if non exiting, since
REM the development tools will not create them themselves
if not exist obj mkdir obj
if not exist bin mkdir bin

echo.
echo Compile the C code
echo --------------------------
compile main.c -o obj\main.asm || goto :failed

echo.
echo Assemble the ASM code
echo --------------------------
assemble obj\main.asm -o obj\main.vbin || goto :failed

echo.
echo Convert the PNG textures
echo --------------------------
png2vircon img\v32atlas01.png -o obj\v32atlas01.vtex || goto :failed

echo.
echo Convert the WAV sounds
echo --------------------------
wav2vircon bgm\Law-in-the-City.wav -o obj\Law-in-the-City.vsnd || goto :failed

echo.
echo Pack the ROM
echo --------------------------
packrom main.xml -o bin\main.v32 || goto :failed
goto :succeeded

:failed
echo.
echo BUILD FAILED
exit /b %errorlevel%

:succeeded
echo.
echo BUILD SUCCESSFUL
exit /b

@echo on