import javax.swing.*;
import java.awt.*;
import java.awt.geom.*;

public class DrawingComponent extends JComponent {

    private int width;
    private int height;
    private int method ;
    private Lab01 lab01;
    private Lab02 lab02;
    public static int cellSize = 30;
    public static double startPoint;

    public DrawingComponent(int w, int h) {
        width = w;
        height = h;
        startPoint = width/2/cellSize;
        lab01 = new Lab01(2, -2, 6, -4);
        lab02 = new Lab02(0, 0, 3, 3);
        setPreferredSize(new Dimension(width, height));
    }

    @Override
    protected void paintComponent(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        setBackgroundToCells(g2d);
        if (method == 1) {
            lab01.dda(g2d);
        } else if (method == 2) {
            lab01.bresenham(g2d);
        } else if (method == 3) {
            lab01.trueSegment(g2d);
        } else if (method == 4) {
            lab02.draw(g2d);
        }
    }

    public void setBackgroundToCells(Graphics2D g2d) {
        for (int i = 0; i < width; i += 30) {
            Line2D.Double vertical = new Line2D.Double(i, 0, i, width);
            Line2D.Double horizontal = new Line2D.Double(0, i, width, i);
            g2d.setColor(Color.BLACK);
            g2d.draw(vertical);
            g2d.draw(horizontal);

        }
        g2d.setColor(Color.GREEN);
        Line2D.Double lineOXY = new Line2D.Double(width/2, 0, width/2, width);
        g2d.draw(lineOXY);
        lineOXY = new Line2D.Double(0, width/2, width, width/2);
        g2d.draw(lineOXY);

    }

    public void setMethod(int m) {
        method = m;
    }
}