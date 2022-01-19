/**********************************
 * Angle Between Hands of a Clock *
 **********************************/

public class Solution {
    public double AngleClock(int hour, int minutes) {
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
        double minuteAngle = minutes * 6;
        
        return Math.Min(Math.Abs(hourAngle - minuteAngle), 360 - Math.Abs(hourAngle - minuteAngle));
    }
}