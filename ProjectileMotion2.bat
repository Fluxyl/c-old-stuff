del p3.out
REM Handles p3 batch testing 1D option 
p3.exe /i /1D < p3_1D_case01.txt >> p3.out
p3.exe /i /ID < p3_1D_case02.txt >> p3.out

REM Handles p3 batch testing 2D option
p3.exe /i /1D < p3_2D_case01.txt >> p3.out
p3.exe /i /ID < p3_2D_case02.txt >> p3.out

REM Handles p3 batch testing Beam option
p3.exe /i /1D < Beam_case01.txt >> p3.out
p3.exe /i /ID < Beam_case02.txt >> p3.out

REM Handles p3 batch testing help option
p3.exe /h >> p3.out
p3.exe /h >> p3.out

REM Handles p3 batch testing no option
p3.exe >> p3.out
