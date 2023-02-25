<Qucs Schematic 0.0.19>
<Properties>
  <View=0,0,1359,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=Ejercicio 3.dat>
  <DataDisplay=Ejercicio 3.dpl>
  <OpenDisplay=1>
  <Script=Ejercicio 3.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Título>
  <FrameText1=Dibujado por:>
  <FrameText2=Fecha:>
  <FrameText3=Revisión:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <R R1 1 700 370 -113 -26 0 3 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <VProbe VL 1 470 120 28 -31 0 0>
  <IProbe IL 1 620 290 -26 16 0 0>
  <.TR TR1 1 140 90 0 79 0 0 "lin" 1 "0" 1 "50 us" 1 "11" 0 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
  <Vdc V1 1 350 370 18 -26 0 1 "10 V" 1>
  <L L1 1 470 290 -26 10 0 0 "10 mH" 1 "0" 0>
</Components>
<Wires>
  <700 400 700 480 "" 0 0 0 "">
  <350 480 700 480 "" 0 0 0 "">
  <350 400 350 480 "" 0 0 0 "">
  <700 290 700 340 "" 0 0 0 "">
  <500 290 550 290 "" 0 0 0 "">
  <350 290 350 340 "" 0 0 0 "">
  <350 290 390 290 "" 0 0 0 "">
  <390 140 460 140 "" 0 0 0 "">
  <390 290 440 290 "" 0 0 0 "">
  <390 140 390 290 "" 0 0 0 "">
  <480 140 550 140 "" 0 0 0 "">
  <550 290 590 290 "" 0 0 0 "">
  <550 140 550 290 "" 0 0 0 "">
  <650 290 700 290 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 920 380 392 250 3 #c0c0c0 1 00 1 0 1e-05 5e-05 1 -0.92589 2 10.9932 1 -1 0.5 1 315 0 225 "t (s)" "V_L (V)" "">
	<"VL.Vt" #0000ff 0 3 0 0 0>
  </Rect>
  <Rect 920 706 396 276 3 #c0c0c0 1 00 1 0 0.2 1 1 -0.1 0.5 1.1 1 -0.1 0.5 1.1 315 0 225 "t (s)" "I_L (A)" "">
	<"IL.It" #0000ff 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
