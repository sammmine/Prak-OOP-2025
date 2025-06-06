import java.util.ArrayList;
import java.util.List;

public class WorkerV2 implements Runnable {

    private List<Task> tasks;

    public WorkerV2(){
        //TODO: Fill with the default constructor of this class.
        this.tasks = new ArrayList<>();
    };

    public void addTask(Task newTask){
        //TODO: Fill with the operation that will add new task to tasks.
        tasks.add(newTask);
    }

    @Override
    public void run() {
        try {
            for (Task executedTask : tasks) {
                Thread.sleep(executedTask.getTime());
                synchronized (executedTask) {
                    executedTask.setStatus("done");
                    executedTask.notify();
                }
            }
            //TODO: Fill with the operation that will process the tasks. Hint: the operation is exactly
            // the same with the operation that exist on Worker.java with a little improvement;)
        } catch (InterruptedException e) {
            //TODO: Fill with the same error message on the Worker.java
            System.out.println("Worker Error!");
        }
    }
    
}