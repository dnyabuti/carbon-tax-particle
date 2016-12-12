# Energy Use Monitor
The purpose of this project is to monitor energy used in kWh over time. 
## Tools used
* [Non-invasive AC Current Sensor Split Core Transformer](https://www.amazon.com/gp/product/B01C5JL5IY/ref=oh_aui_detailpage_o07_s00?ie=UTF8&psc=1)
* [Photon](https://store.particle.io/#photon) 

I use the Split Core Transformer to read the current flow every second. This readings are stored in an array for 10 seconds. After 10 seconds I convert the current to kWh and publish an event with the reading to the cloud. After this the array is emptied and the cycle starts over again.
