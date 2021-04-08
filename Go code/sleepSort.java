
class CreateThread extends Thread{
    int value;
    CreateThread(int value){
        this.value = value;
    }
    public void run(){
        try {
            int sleepingTime = this.value;
            Thread.sleep(1000L * sleepingTime); // multiplying 1000 for converting milli sec to sec
            System.out.print(this.value + " ");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class SleepSort {
    public static void main(String[] args) {
        int[] values = {5, 2, 4, 1, 1, 1, 6};
        for( int x : values ){
            new CreateThread(x).start();
        }
    }
}
