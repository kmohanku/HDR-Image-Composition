import matplotlib.pyplot as plt
from scipy import stats
import numpy as np

LOGTi = np.array([-3, -2.875169851, -2.698970004, -2.54408976, -2.397940009, -2.255237763, -2.096910013, -1.954246852, -1.778142565, -1.653216857])
B_bar_red = (1.62324929, 1.740362689, 1.875061263, 1.986771734, 2.06069784, 2.100370545, 2.178976947, 2.222716471, 2.276461804, 2.28780173)
B_Bar_Green = (1.643452676, 1.755874856, 1.897627091, 2.008600172, 2.075546961, 2.120573931, 2.198657087, 2.243038049, 2.294466226, 2.307496038)
B_Bar_Blue = (1.568201724, 1.69019608, 1.838849091, 1.949390007, 2.021189299, 2.06069784, 2.146128036, 2.193124598, 2.250420002, 2.264817823)

BR = (2494.405679, 4259.320674, 8362.534675, 14181.29659, 19502.61888, 24163.63804, 35039.49579, 43280.46885, 55283.10758, 58819.95329)
BG = (2262.111092, 3949.424048, 7497.114046, 12757.0005, 18135.10296, 21903.08875, 31838.22499, 39204.72755, 50629.71285, 53436.73377)
BB=(1292.740507, 2257.166785, 4451.53816, 7376.278655, 10239.91209, 12265.52639, 18121.34994, 22461.44516, 29182.26872, 31166.3653)

T = (0.001, 0.001333, 0.002, 0.002857, 0.004, 0.005556, 0.008, 0.011111, 0.016667, 0.022222)
B_Bluedash =np.array([37, 49, 69, 89, 105, 115, 140, 156, 178, 184])
B_Reddash =np.array([44, 57, 79, 102, 119, 132, 158, 175, 197, 203])
B_Greendash =np.array([42, 55, 75, 97, 115, 126, 151, 167, 189, 194])

slope_Blue, intercept_Blue, r_valueb, p_valueb, std_errb = stats.linregress(LOGTi, B_Bar_Blue)
slope_Green, intercept_Green, r_valueg, p_valueg, std_errg = stats.linregress(LOGTi, B_Bar_Green)
slope_Red, intercept_Red, r_valuer, p_valuer, std_errr = stats.linregress(LOGTi, B_bar_red)

L_G = []

print ("Red_Slope = ", slope_Red)
print ("Red_Intercept = ", intercept_Red)
print ("Green_Slope = ", slope_Green)
print ("Green_Intercept = ", intercept_Green)
print ("Blue_Slope = ", slope_Blue)
print ("Blue_Intercept = ", intercept_Blue)

plt.plot(T, B_Bluedash, "o",color='b')
plt.plot(T, B_Greendash, "o",color='g')
plt.plot(T, B_Reddash, "o", color ='r')
plt.xlabel('Ti')
plt.ylabel("B'")
plt.show()


plt.plot(LOGTi, B_Bar_Blue, "o",color='b',)
plt.plot(LOGTi, B_Bar_Green, "o",color='g')
plt.plot(LOGTi, B_bar_red, "o", color ='r')
plt.plot(LOGTi, (slope_Red*LOGTi + intercept_Red),"-", color = 'r',label='Red Regression Line')
plt.plot(LOGTi, (slope_Blue*LOGTi + intercept_Blue),"-",color = 'b',label="Blue Regression Line")
plt.plot(LOGTi, (slope_Green*LOGTi + intercept_Green),"-",color = 'g',label="Green Regression Line")
plt.legend(loc='upper left')
plt.xlabel('LOG(Ti)')
plt.ylabel("LOG(B')")
plt.show()

plt.plot(T, BB, "o",color='b')
plt.plot(T, BG, "o",color='g')
plt.plot(T, BR, "o", color ='r')
plt.xlabel('Ti')
plt.ylabel('B')
plt.show()
