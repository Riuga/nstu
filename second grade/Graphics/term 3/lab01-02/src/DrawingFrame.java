import javax.swing.*;
import java.awt.*;

public class DrawingFrame extends JFrame {

    private int width;
    private int height;
    private String title;

    public DrawingFrame(int w, int h, String t) {
        width = w;
        height = h;
        title = t;
    }

    public void setUpFrame() {
        Container contentPane = getContentPane();
        DrawingComponent drawingComponent = new DrawingComponent(width, height);
        Buttons buttons = new Buttons(drawingComponent);
        buttons.setUpLabs();
        setTitle(title);
        contentPane.add(drawingComponent, BorderLayout.CENTER);
        contentPane.add(buttons, BorderLayout.SOUTH);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }
}