
doxygen DoxyfileQudraticCalc

cd html

iconv -f UTF-8 -t CP1251 index.hhc > index.hhc.1251
if not errorlevel 1 move /y  index.hhc.1251 index.hhc

iconv -f UTF-8 -t CP1251 index.hhk > index.hhk.1251
if not errorlevel 1 move /y  index.hhk.1251 index.hhk

if exist QuadraticCalc.chm del QuadraticCalc.chm
if exist QuadraticCalc.chi del QuadraticCalc.chi

hhc index.hhp
start QuadraticCalc.chm