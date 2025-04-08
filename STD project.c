package ap.exercises.ex2;

import java.util.Random;
import java.util.Scanner;

public class Main_EX2_PM_1_5 {
    public static void main(String[] args) {
        System.out.println("please enter the size of the square:");
        Scanner s = new Scanner(System.in);
        int k = s.nextInt();
        int n = 1, m = 1;
        char[][] Arr = new char[k+2][k+2];
        for (int i = 0; i < k + 2 ; i++) {
            for (int j = 0; j < k + 2; j++) {
                if (i == 0 || i == k + 1 || j == 0 || j == k + 1)
                {
                    Arr[i][j] = '*';
                }
                else {
                    Arr[i][j] = ' ';
                }
            }
        }
        while (true) {
            Random random = new Random();
            int rand = random.nextInt(4);
            System.out.println(rand);
            switch (rand) {
                case 0:{
                    System.out.println("UP");
                    n--;
                } break;
                case 1:{
                    System.out.println("RIGHT");
                    m++;
                } break;
                case 2:{
                    System.out.println("DOWN");
                    n++;
                } break;
                case 3:{
                    System.out.println("LEFT");
                    m--;
                } break;
            }
            System.out.println(m);
            if (m == 0 || n == 0 || m == k - 1 || n == k - 1)
            {
                System.out.println("hitting the game wall");
            }
            else{
                Arr[n][m] = 'X';
                for (int i = 0; i < k + 2; i++) {
                    for (int j = 0; j < k + 2; j++) {
                        System.out.print(Arr[i][j]);
                    }
                    System.out.println(" ");
                }
            }
            Arr [n][m] = ' ';

        }
    }
}
import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;

public class PacmanGUI extends JFrame implements KeyListener {

Point pacmanPoint = new Point();
final int width = 300, height = 300, boxSize = 5;
static int direction = 1;
final int LEFT = 1, RIGHT = 2, TOP = 3, BOTTOM = 4;
Point dotPoint = new Point();

public PacmanGUI() {
    addKeyListener(this);
    pacmanPoint.setLocation((width / boxSize) / 2, (height / boxSize) / 2);
    getNewDotPointLocation();
    setSize(width, height);
}

@Override
public void paint(Graphics g) {
    Graphics2D g2D = (Graphics2D) g;
    g.clearRect(0, 0, width, height);
    logic();
    drawPacman(g2D);
    drawDotPoint(g2D);
    drawScore(g2D);
    setVisible(true);
}

private void drawPacman(Graphics2D g2d) {
    g2d.setColor(Color.BLUE);
    g2d.fillRect(pacmanPoint.x * boxSize, pacmanPoint.y * boxSize, boxSize, boxSize);
}

private void drawDotPoint(Graphics2D g2d) {
    g2d.setColor(Color.RED);
    g2d.fillRect(dotPoint.x * boxSize, dotPoint.y * boxSize, boxSize, boxSize);
}

private void drawScore(Graphics2D g2d) {
    g2d.setColor(Color.BLACK);
    String s = "Score: 0";
    g2d.drawString(s, 25, 50);
}

private void logic() {
    if (dotPoint.x == pacmanPoint.x && dotPoint.y == pacmanPoint.y) {
        getNewDotPointLocation();
    }
    movePacman();
}

private void movePacman() {
    int xMovement = 1;
    int yMovement = 0;
    switch (direction) {
        case LEFT:
            xMovement = -1;
            yMovement = 0;
            break;
        case RIGHT:
            xMovement = 1;
            yMovement = 0;
            break;
        case TOP:
            xMovement = 0;
            yMovement = -1;
            break;
        case BOTTOM:
            xMovement = 0;
            yMovement = 1;
            break;
        default:
            xMovement = yMovement = 0;
            break;
    }
    pacmanPoint.setLocation(pacmanPoint.x + xMovement, pacmanPoint.y + yMovement);
    handleCrossBorder();
}

private void getNewDotPointLocation() {
    Random rand = new Random();
    int delta = boxSize * 2;
    dotPoint.setLocation(rand.nextInt(width / boxSize - 2 * delta) + delta, rand.nextInt(height / boxSize - 2 * delta) + delta);
}


@Override
public void keyTyped(KeyEvent e) {
}

@Override
public void keyPressed(KeyEvent e) {
    if (e.getKeyCode() == KeyEvent.VK_UP)
        direction = 3;
    else if (e.getKeyCode() == KeyEvent.VK_DOWN)
        direction = 4;
    else if (e.getKeyCode() == KeyEvent.VK_LEFT)
        direction = 1;
    else if (e.getKeyCode() == KeyEvent.VK_RIGHT)
        direction = 2;
    else if (e.getKeyCode() == KeyEvent.VK_P)
        direction = 0;
    else
        direction = -1;

    System.out.println("direction:" + direction + "    <- e.getKeyCode()=" + e.getKeyCode());

    repaint();
}

@Override
public void keyReleased(KeyEvent e) {
}

private void handleCrossBorder() {
    //
}
import java.util.*;

public class Main {

   public static void main(String[] args) {

    int k=9; //عدد مربوط به تمرین EX2_PM_1_1 و EX2_PM_1_2
    int c=15; //عدد مربوط به تمرین EX2_PM_1_3

    Random rnd = new Random();

    PacmanEngine pacmanEngine = new PacmanEngine(k,c);

    while(true) {
        pacmanEngine.printMatrix(); // مربوط به بخش آخر تمرین EX2_PM_1_3
        pacmanEngine.printScore(); // امتیاز تمرین EX2_PM_2_2
        pacmanEngine.printRemainTime(); // زمان تمرین EX2_PM_2_2

        try {
            Thread.sleep(2000);
        } catch (Exception e) {}

        int direction=rnd.nextInt(4);
        pacmanEngine.move(direction);// حرکت نقطه خوار مربوط به تمرین EX2-PM.1.5
        pacmanEngine.save();
    }

}
}





public static void main(String[] args) {
    PacmanGUI frame = new PacmanGUI();
    frame.setVisible(true);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}


