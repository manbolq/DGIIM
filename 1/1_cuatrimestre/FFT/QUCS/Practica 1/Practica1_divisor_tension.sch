<Qucs Schematic 0.0.19>
<Properties>
  <View=130,-59,1227,780,1,0,0>
  <Grid=10,10,1>
  <DataSet=Practica1_divisor_tension.dat>
  <DataDisplay=Practica1_divisor_tension.dpl>
  <OpenDisplay=1>
  <Script=Practica1_divisor_tension.m>
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
  <Vdc V1 1 390 330 18 -26 0 1 "10 V" 1>
  <GND * 1 630 420 0 0 0 0>
  <VProbe Sonda_1 1 650 100 28 -31 0 0>
  <.DC DC1 1 180 50 0 47 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <VProbe Sonda_2 1 1080 180 28 -31 0 0>
  <IProbe Sonda_3 1 460 240 -26 16 0 0>
  <IProbe Sonda_4 1 790 240 -51 17 0 0>
  <R R1 1 650 240 -26 15 0 0 "2.2 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R2 1 840 330 15 -26 0 1 "4.7 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
</Components>
<Wires>
  <390 240 390 300 "" 0 0 0 "">
  <390 240 430 240 "" 0 0 0 "">
  <680 240 720 240 "" 0 0 0 "">
  <840 240 840 270 "" 0 0 0 "">
  <840 360 840 390 "" 0 0 0 "">
  <390 420 630 420 "" 0 0 0 "">
  <390 360 390 420 "" 0 0 0 "">
  <630 420 840 420 "" 0 0 0 "">
  <570 120 640 120 "" 0 0 0 "">
  <570 240 620 240 "" 0 0 0 "">
  <570 120 570 240 "" 0 0 0 "">
  <660 120 720 120 "" 0 0 0 "">
  <720 240 760 240 "" 0 0 0 "">
  <720 120 720 240 "" 0 0 0 "">
  <1070 200 1070 270 "" 0 0 0 "">
  <840 270 840 300 "" 0 0 0 "">
  <840 270 1070 270 "" 0 0 0 "">
  <1090 200 1090 390 "" 0 0 0 "">
  <840 390 840 420 "" 0 0 0 "">
  <840 390 1090 390 "" 0 0 0 "">
  <490 240 570 240 "" 0 0 0 "">
  <820 240 840 240 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Tab 440 630 541 65 3 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 1 315 0 225 "" "" "">
	<"Sonda_1.V" #0000ff 0 3 1 0 0>
	<"Sonda_2.V" #0000ff 0 3 1 0 0>
	<"Sonda_3.I" #0000ff 0 3 1 0 0>
	<"Sonda_4.I" #0000ff 0 3 1 0 0>
  </Tab>
</Diagrams>
<Paintings>
</Paintings>
