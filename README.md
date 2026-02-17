# 📘 Digital Library in C #
The library was developed in C language and tested on the STM32F446RE microcontroller. But it can be used with any controller that supports the C language, or it can be easily translated into C++ as well. 
The library is categorized as follows:
- Digital Power Library (DPL)
- Digital Control Library (DCL)

The controller software structure is as follows: 
<img width="1045" height="512" alt="image" src="https://github.com/user-attachments/assets/69e65cd2-3729-4b35-8bd2-5a29d039eb5c" />


## 📂 Library File Structure ##
Every Library has the following file structure
```
Library Base Folder
 ├── inc/
 |    ├── Library Header Files
 └── src/
 |    ├── Library Source Code
```

## Digital Power Library (DPL) ##
DPL consists of the following libraries:
- SA_PLL_3PH_SRF => 3ph SRF PLL
- SA_ABC_INVERSE_TRANSFORM => DQ0 to ABC Transform
- SA_ABC_TRANSFORM => ABC to DQ0 Transform
- SA_ALPHABETA_TO_ABC => Alpha-Beta to ABC
- SA_PLL_3PH_DDSRF => 3ph DDSRF PLL
- SA_PLL_3PH_DSOGI => 3ph DSOGI PLL
- SA_POWER_3PH => Calculate 3ph AC power
- SA_POWER_DC => Calculate DC power
- SA_RAMP => Ramp Generation
- SA_SENSOR_MANAGE => Manage Sensor Data

## 🚀 Usage of DPL ##
<img width="872" height="598" alt="image" src="https://github.com/user-attachments/assets/101d7db3-6b54-45be-b3fd-f2b9204106f5" />

