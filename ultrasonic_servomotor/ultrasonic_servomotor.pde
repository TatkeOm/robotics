import java.util.Random;

public class ServoDistanceSimulator {

    public static void main(String[] args) {
        // Simulate the servo and distance measurement
        int trigPin = 10;  // Unused in this simulation, but retained for clarity
        int echoPin = 11;  // Unused in this simulation, but retained for clarity
        boolean var = true;

        float duration, distance;
        Random rand = new Random();

        // Simulate the Servo motor moving from 0 to 180 degrees
        for (int angle = 0; angle <= 180; angle += 3) {
            System.out.println("Servo Angle: " + angle);
            // Simulate a small delay for motor movement
            try {
                Thread.sleep(20);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            // Simulate ultrasonic sensor behavior
            duration = rand.nextFloat() * 1000;  // Simulated pulse duration
            distance = (duration * 0.0343f) / 2;
            System.out.println("Distance: " + distance + " cm");

            // Simulate the delay between readings
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // Wait before reversing the movement
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Simulate the Servo motor moving from 180 to 0 degrees
        for (int angle = 180; angle >= 0; angle -= 3) {
            System.out.println("Servo Angle: " + angle);
            // Simulate a small delay for motor movement
            try {
                Thread.sleep(20);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            // Simulate ultrasonic sensor behavior
            duration = rand.nextFloat() * 1000;  // Simulated pulse duration
            distance = (duration * 0.0343f) / 2;
            System.out.println("Distance: " + distance + " cm");

            // Simulate the delay between readings
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // Wait before the next loop iteration
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
