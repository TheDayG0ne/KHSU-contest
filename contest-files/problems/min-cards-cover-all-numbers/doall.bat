rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=1000 -t=rand -d=100" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=1000 -t=rand -d=5" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=0 1" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=0 2" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=0 3" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=0 4" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=0 5" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=1" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=2" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=3" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=333" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=10000" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=20000" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=25000" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=50000" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=100000" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\gen.exe -n=100000 -t=rand -d=99900" "tests\20" 20
call scripts\gen-answer.bat tests\01 tests\01.a "tests" ""
call scripts\gen-answer.bat tests\02 tests\02.a "tests" ""
call scripts\gen-answer.bat tests\03 tests\03.a "tests" ""
call scripts\gen-answer.bat tests\04 tests\04.a "tests" ""
call scripts\gen-answer.bat tests\05 tests\05.a "tests" ""
call scripts\gen-answer.bat tests\06 tests\06.a "tests" ""
call scripts\gen-answer.bat tests\07 tests\07.a "tests" ""
call scripts\gen-answer.bat tests\08 tests\08.a "tests" ""
call scripts\gen-answer.bat tests\09 tests\09.a "tests" ""
call scripts\gen-answer.bat tests\10 tests\10.a "tests" ""
call scripts\gen-answer.bat tests\11 tests\11.a "tests" ""
call scripts\gen-answer.bat tests\12 tests\12.a "tests" ""
call scripts\gen-answer.bat tests\13 tests\13.a "tests" ""
call scripts\gen-answer.bat tests\14 tests\14.a "tests" ""
call scripts\gen-answer.bat tests\15 tests\15.a "tests" ""
call scripts\gen-answer.bat tests\16 tests\16.a "tests" ""
call scripts\gen-answer.bat tests\17 tests\17.a "tests" ""
call scripts\gen-answer.bat tests\18 tests\18.a "tests" ""
call scripts\gen-answer.bat tests\19 tests\19.a "tests" ""
call scripts\gen-answer.bat tests\20 tests\20.a "tests" ""

