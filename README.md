# Intelligent-Garbage-Sorting-Robot
1. Garbage identification and sorting  
Use a USB camera to act as the robot's eyes for garbage recognition and sorting. For convenience, it uses three different colored squares, red, yellow and blue, to 
represent different types of trash. The USB camera which is connected to the Raspberry PI continuously scans the live feed for the target object. Then, use image processing technology to divide the frames and digitize the images. Secondly, judge the garbage type according to the aggregated pixels. The Raspberry PI is connected to an Arduino board using two Jumper wires which will send the information to the Arduino board using a bits communication method. For example, Red is represented as 10, where 1 is high volt and 0 is low volt. Then the robotic arm will perform operation depending upon the information passed from the Raspberry PI board.  
2. Robotic arm  
Use a 4-degree-of-freedom robotic arm for waste transportation. The first degree of freedom is responsible for horizontal rotation; the second degree of freedom and the third degree of freedom are responsible for the choice of vertical direction. The fourth degree of freedom is responsible for garbage capture and release. The robotic arm is connected to an Arduino board, which can receive information passed from the Raspberry PI. When the robotic arm receives the signal from the camera, it picks up the garbage and transports it to the corresponding garbage can according to the different signals. The basic principle of our transportation is to find the shortest transportation path while ensuring the stability of the robotic arm.  
3. The smart trash cans  
Use four garbage cans to hold different categories of garbage. In order to automate the waste sorting process, we wanted the bins to open and close the lids automatically. So each bin is equipped with two ultrasonic sensors, one to detect if the robot arm has selected this bin and the other to detect if this bin is full. When the bin is full, it will no longer open the lid, but send a light signal to the robotic arm's camera by turning on the light.
