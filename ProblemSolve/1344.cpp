/**********************************
 * Angle Between Hands of a Clock *
 **********************************/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
        double minuteAngle = minutes * 6;
        
        return min(abs(hourAngle - minuteAngle), 360 - abs(hourAngle - minuteAngle));
    }
};