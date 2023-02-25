<Qucs Schematic 0.0.19>
<Properties>
  <View=0,0,1432,860,1,0,0>
  <Grid=10,10,1>
  <DataSet=Practica1_ejercicio3_intensidades.dat>
  <DataDisplay=Practica1_ejercicio3_intensidades.dpl>
  <OpenDisplay=1>
  <Script=Practica1_ejercicio3_intensidades.m>
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
  <Idc I1 1 350 350 18 -26 0 1 "1 mA" 1>
  <Vdc V1 1 900 210 18 -26 0 1 "5 V" 1>
  <R R1 1 500 210 -26 15 0 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R2 1 750 60 -26 15 0 0 "2 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R3 1 750 350 -26 15 0 0 "3 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R4 1 1050 60 -26 15 0 0 "4 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R5 1 1080 350 -26 15 0 0 "5 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <IProbe Sonda_1 1 410 210 -26 16 0 0>
  <IProbe Sonda_3 1 670 350 -26 16 0 0>
  <IProbe Sonda_4 1 960 60 -26 16 0 0>
  <IProbe Sonda_int 1 510 550 -26 16 1 2>
  <IProbe Sonda_tens 1 901 299 16 -26 0 1>
  <.DC DC1 1 170 80 0 47 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <IProbe Sonda_2 1 670 60 -26 16 1 2>
  <IProbe Sonda_5 1 980 350 -26 16 1 2>
</Components>
<Wires>
  <350 210 350 320 "" 0 0 0 "">
  <350 210 380 210 "" 0 0 0 "">
  <780 350 900 350 "" 0 0 0 "">
  <620 350 640 350 "" 0 0 0 "">
  <620 210 620 350 "" 0 0 0 "">
  <780 60 900 60 "" 0 0 0 "">
  <620 60 640 60 "" 0 0 0 "">
  <620 60 620 210 "" 0 0 0 "">
  <530 210 620 210 "" 0 0 0 "">
  <900 60 900 180 "" 0 0 0 "">
  <900 240 900 350 "" 0 0 0 "">
  <900 60 930 60 "" 0 0 0 "">
  <1150 60 1150 350 "" 0 0 0 "">
  <350 550 480 550 "" 0 0 0 "">
  <350 380 350 550 "" 0 0 0 "">
  <1150 350 1150 550 "" 0 0 0 "">
  <900 350 950 350 "" 0 0 0 "">
  <1080 60 1150 60 "" 0 0 0 "">
  <1110 350 1150 350 "" 0 0 0 "">
  <440 210 470 210 "" 0 0 0 "">
  <700 60 720 60 "" 0 0 0 "">
  <700 350 720 350 "" 0 0 0 "">
  <990 60 1020 60 "" 0 0 0 "">
  <1010 350 1050 350 "" 0 0 0 "">
  <540 550 1150 550 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Tab 290 730 875 67 3 #c0c0c0 1 00 1 0 1 1 1 0 1 1 1 0 1 1 315 0 225 "" "" "">
	<"Sonda_1.I" #0000ff 0 3 1 0 0>
	<"Sonda_2.I" #0000ff 0 3 1 0 0>
	<"Sonda_3.I" #0000ff 0 3 1 0 0>
	<"Sonda_4.I" #0000ff 0 3 1 0 0>
	<"Sonda_5.I" #0000ff 0 3 1 0 0>
	<"Sonda_int.I" #0000ff 0 3 1 0 0>
	<"Sonda_tens.I" #0000ff 0 3 1 0 0>
  </Tab>
</Diagrams>
<Paintings>
</Paintings>
