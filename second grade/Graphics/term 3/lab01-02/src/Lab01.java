import java.awt.*;
import java.awt.geom.*;

public class Lab01 {
    private double x;
    private double x1;
    private double x2;
    private double y;
    private double y1;
    private double y2;
    private double dx;
    private double dy;
    private double length;

    public Lab01(double x1, double y1, double x2, double y2) {
        if(x1>x2) {
            this.x1 = x2 + DrawingComponent.startPoint;
            this.y1 = -y2 + DrawingComponent.startPoint;
            this.x2 = x1 + DrawingComponent.startPoint;
            this.y2 = -y1 + DrawingComponent.startPoint;
        } else {
            this.x1 = x1 + DrawingComponent.startPoint;
            this.y1 = -y1 + DrawingComponent.startPoint;
            this.x2 = x2 + DrawingComponent.startPoint;
            this.y2 = -y2 + DrawingComponent.startPoint;
        }
    }

    public void dda(Graphics2D g2d) {
        length = Math.max(Math.abs(x2 - x1), Math.abs(y2 - y1));
        dx = (x2 - x1) / length;
        dy = (y2 - y1) / length;
        x = x1 + 0.5 * Math.signum(dx);
        y = y1 + 0.5 * Math.signum(dy);
        for (int i = 0; i <= length; i++) {
            g2d.setColor(Color.CYAN);
            Rectangle2D.Double rectangle = new Rectangle2D.Double(Math.floor(x) * DrawingComponent.cellSize, Math.floor(y) * DrawingComponent.cellSize, DrawingComponent.cellSize, DrawingComponent.cellSize);
            g2d.fill(rectangle);
            x += dx;
            y += dy;
        }
        g2d.setColor(Color.RED);
        Line2D.Double pixel = new Line2D.Double(Math.floor(x1) * DrawingComponent.cellSize, Math.floor(y1) * DrawingComponent.cellSize, Math.floor(x2 + 1) * DrawingComponent.cellSize, Math.floor(y2 + 1) * DrawingComponent.cellSize);
        g2d.draw(pixel);
    }

    public void bresenham(Graphics2D g2d) {
        dx = x2 - x1;
        dy = y2 - y1;
        double alpha = Math.atan(dy / dx);
        int x = (int) Math.floor(x1 + 0.5 * (dx >= 0 ? 1 : -1));
        int y = (int) Math.floor(y1 + 0.5 * (dy >= 0 ? 1 : -1));
        double e = (alpha < Math.PI / 4) ? 2 * dy - dx : 2 * dx - dy;
        g2d.setColor(Color.PINK);
        for (int i = 0; i <= (alpha < Math.PI / 4 ? dx : dy); i++) {
            Rectangle2D.Double rectangle = new Rectangle2D.Double(x * DrawingComponent.cellSize, y * DrawingComponent.cellSize, DrawingComponent.cellSize, DrawingComponent.cellSize);
            g2d.fill(rectangle);
            while (e > 0) {
                if (alpha < Math.PI / 4) {
                    y++;
                    e -= 2 * dx;
                } else {
                    x++;
                    e -= 2 * dy;
                }
            }
            if (alpha < Math.PI / 4) {
                x++;
                e += 2 * dy;
            } else {
                y++;
                e += 2 * dx;
            }
        }
        g2d.setColor(Color.BLUE);
        Line2D.Double line = new Line2D.Double(x1 * DrawingComponent.cellSize, y1 * DrawingComponent.cellSize, (x2+1) * DrawingComponent.cellSize, (y2+1) * DrawingComponent.cellSize);
        g2d.draw(line);
    }

    public void trueSegment(Graphics2D g2d) {
        g2d.setColor(Color.MAGENTA);
        Line2D.Double trueLine = new Line2D.Double(x1 * DrawingComponent.cellSize, y1 * DrawingComponent.cellSize, (x2+1) * DrawingComponent.cellSize, (y2+1) * DrawingComponent.cellSize);
        g2d.draw(trueLine);
    }
}