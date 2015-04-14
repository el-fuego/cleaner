# Robo-cleaner
**Робот-прибиральник поломийка з можливістю групової роботи та самоочищення.** <br />
Базується на Arduino Pro mini. <br />
Має контроллер двигунів, оптичний датчик перешкод, компас, модуль зв’язку, датчик пересування/відстані

#### Конструктив
* Arduino Pro mini Mega 328 5v 16MHz (стабільний за напруги 3.7V) http://ru.aliexpress.com/item/2Pcs-Lot-Pro-Mini-Module-Atmega328-5V-16M-For-Arduino-Compatible-Nano/710618765.html
* Макетна плата http://ru.aliexpress.com/item/chinafactory-New-240-Point-Solderless-PCB-Breadboard-Bread-Board-8-5mm-SYB-46-High-Qualit/1768228227.html
* Контроллер двигунів з регулюванням потужності TB6612FNG http://ru.aliexpress.com/item/Dual-Motor-Driver-1A-TB6612FNG-for-Arduino-Microcontroller-Free-Shipping/2027583785.html
* Оптичний датчик перешкод (саморобний) ІЧ фототранзистор, фотодіод, резистори 100K та 200R 
* Магнетометр (компас) HMC5883L (очікується доставка) http://ru.aliexpress.com/item/Free-Shipping-GY-273-HMC5883L-Module-Triple-Axis-Compass-Magnetometer-Sensor-3V-5V-Dropshipping-In-stock/1858848636.html
* Модуль зв’язку NRF24L01 (очікується доставка) http://ru.aliexpress.com/item/2Pcs-x-NRF24L01-Wireless-Module-2-4G-Wireless-Communication-Module-Upgrade-Module/690124181.html

* Макетні пласкі пластикові панелі http://ru.aliexpress.com/item/DIY-Plastic-Board-Technology-Production-of-Chassis-Features-Panel-with-Holes-Plastic-Film-Free-Shipping-10/1908632603.html
* Макетні пластикові полоски http://ru.aliexpress.com/item/plastic-article-1116-Connecting-rod-fixed-rod-universal-rod-DIY-production-Angle-science-and-technology/1854218185.html
* Металеві стрижні для з’єднання http://ru.aliexpress.com/item/2-x-100mm-DIY-Toy-Axle-Short-Axis-Connecting-Rod-Drive-Shaft-Gear-shaft-Pulley-shaft/1620773806.html
* Опорне колесо http://ru.aliexpress.com/item/10pcs-DC-3v-5v-Worm-Gear-Motor-Variable-Speed-Gearmotor-micro-reduction-gear-box/1680398318.html

* Ведучі колеса з моторами і пластиковими редукторами 3-6V, 95-230 RPM http://ru.aliexpress.com/item/Free-shipping-4-set-Smart-Car-Robot-Plastic-Tire-Wheel-Tyre-DC3-6V-Gear-Motor-For/1918314363.html
* Мотор піднімання платформи з пластиковим редуктором 3-5V, 80-130 RPM http://ru.aliexpress.com/item/10pcs-DC-3v-5v-Worm-Gear-Motor-Variable-Speed-Gearmotor-micro-reduction-gear-box/1680398318.html
* Li-ion 3.7V батарея формату 18650 http://ru.aliexpress.com/item/Firepeak-18650-3200mAh-3-7V-Rechargeable-Li-ion-Battery/769408094.html
* Тримач батареї http://ru.aliexpress.com/item/A96-Free-Shipping-New-Black-Plastic-Storage-Box-Case-Holder-For-Battery-18650-With-6-Wire/1965893745.html
* Зарядний модуль для батареї mini-USB http://ru.aliexpress.com/item/High-Quality-New-1PCS-5V-Mini-USB-1A-Lithium-Battery-Charging-Board-Charger-Module-b7-TK0458/1834368438.html
* USB-RS232 адаптер для програмування http://ru.aliexpress.com/item/D19-Free-Shipping-PL2303-USB-To-RS232-TTL-Converter-Adapter-Module-For-Arduino-CAR-Detection-GPS/1978924029.html

##### Платформа
https://vk.com/album16471782_185124159

##### Оптичний датчик перешкод
* v1. Постійно увімкнений світлодіод (робота не стабільна) http://i.stack.imgur.com/HC4iL.jpg 
* v2. Увімкнення світлодіода лише на час вимірювання (наразі тестується) https://encrypted-tbn3.gstatic.com/images?q=tbn:ANd9GcR8r_yejtI-IzwuLMbHaclT2u_af_bMlZhbMC1efKo0DIavb5qpUg
Розрахунки для вибору алгоритму https://docs.google.com/spreadsheets/d/12xX7K3GLwI0BPLQ0AKeEQVDjNHkFd4nQ7HoS5wBKhic/edit?usp=sharing


#### Проблеми
##### Платформа
* Потребує зменшення швидкості перед зупинками
* Різний обертаючий момент окремого колеса при навантаженні платформою
* Швидкість руху залежить від навантаження
* Б’ється о перешкоди

##### Оптичний датчик перешкод
* "Залипання" на перешкоді
* Не розпізнає перешкоди чорного кольору
* Погана робота за засвітлення та швидкого змінення яскравості

#### Рішення 
##### Платформа
* Керування швидкістю коліс при запланованих зупинках та наближенні до перешкод
* Додати датчик пересування з оптичної миші та компас (?) для корегування швидкості окремого колеса при русі вперед/назад. Компас для чыткого повороту на 180*
* Встановити датчии перешкод через кожні 30 мм та бампер з датчиками поштовху (? можливе використання датчику руху)

##### Оптичний датчик перешкод
* Перероблення алгоритму на періодичне вмикання світлодіода
* Корегування алгоритму чи оптичне екранування фототранзистора

Для датчику пересування обрано ADNS чіп.
```
These are the current LED ones:
ADNS-5020-EN
ADNS-5050
And the laser ones are:
ADNS-7530
ADNS-7550
ADNS-9500
ADNS-9800
```
http://www.daenotes.com/sites/default/files/field/blog-images/Optical_mouse.jpg
