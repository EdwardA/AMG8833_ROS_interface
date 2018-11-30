# AMG8833_ROS_interface
This repo hopes to not only connect the AMG8833 to ROS, but also publish the data onto RVIS and combine with a turtle bot for data capture.

This repo currently uses pyserial to read the data from arduino, and by removing the centre line of temperature data this can be used as intensity within a laserscan as a placeholder without a dedicated message type.
