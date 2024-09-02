import java.io.IOException;
import java.io.RandomAccessFile;

public class day2problem1 {
    public static void main(String[] args) {
        String f = "p2test.txt";
        try {
            RandomAccessFile file = new RandomAccessFile(f, "r");
            String line;

            while ((line = file.readLine()) != null) {
                System.out.println(line);
            }

            file.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
