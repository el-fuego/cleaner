# IR Barrier Sensor with LED turned for measurements only
=======================

 - **Can`t calibrate if lightness changes very fast (robot turn around)**<br/>
 - Sensivity reduction on sun lightness<br/>
 - Measure with dalay only (default is 1 ms)<br/>
 + Use sensor calibration to ignore lightness changes<br/>
 + Use less power<br/>
 + High sensivity (70mm at evening lights)<br/>
 + Can detect black objects (30mm at evening lights)<br/>
 + Can use getRaw() to check how far barrier is

#### Curcit
```
Dout -----------+-) ->  LED
GND  -------------) ->

Vcc  --=200K=--
Ain  ---------^-+-( <-  Photodiode
GND  -------------( <-
```
Vcc is +3..9V. <br/>
For lager voltage 

#### Algorithm
1. Measure sensor values with LED turned OFF and ON
2. Calibrate sensors on robot power ON (store current sensors values)
4. Barrier is detected when calibrated and current values with LED turned ON deviation is more than limit
5. Calibrate sensor if don`t have barrier and old calibrated and current values with LED turned OFF is more than limit

#### Fast ligtness changes problem
Can`t catch calibration, when moving from darkness to lightness is very fast<br/>

You can use **senfor screening** from daylights for this and sensivity problem

```
   black         sun rays
   screen        / / / / /
------------------/     /
sensor=)        \/     /
------------------ \  /
___ground___________\/__
```