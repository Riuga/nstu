import java.awt.*;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;

public class Lab02 {
    private double x1;
    private double x2;
    private double y1;
    private double y2;
    private int cellSize = 200;
    private int[][] matrix = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}};
    private int mLen = matrix.length;
    private boolean[][] isIntersected = new boolean[mLen][mLen];
    private int sum;
    private int all;

    public Lab02(double x1, double y1, double x2, double y2) {
        if(x1>x2) {
            this.x1 = x2 * cellSize;
            this.y1 = y2 * cellSize;
            this.x2 = x1 * cellSize;
            this.y2 = y1 * cellSize;
        } else {
            this.x1 = x1 * cellSize;
            this.y1 = y1 * cellSize;
            this.x2 = x2 * cellSize;
            this.y2 = y2 * cellSize;
        }
    }

    public boolean isIntersectLine (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
        double u = ((x1 - x3) * (y1 - y2) - (y1 - y3) * (x1 - x2)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
        return t >= 0 && t <= 1 && u >= 0 && u <= 1;
    }

    public boolean isIntersectSquare (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        return isIntersectLine(x1, y1, x2, y2, x3, y3, x4, y3)
                || isIntersectLine(x1, y1, x2, y2, x4, y3, x4, y4)
                || isIntersectLine(x1, y1, x2, y2, x3, y4, x4, y4)
                || isIntersectLine(x1, y1, x2, y2, x3, y3, x3, y4);
    }

    public void draw(Graphics2D g2d) {
        for (int i = 0; i < mLen; i++) {
            for (int j = 0; j < mLen; j++) {
                isIntersected[i][j] = isIntersectSquare(x1, y1, x2, y2, (double)i * cellSize, (double)j*cellSize, (double)(i+1)*cellSize, (double)(j+1) * cellSize);
                if (isIntersected[i][j]) {
                    sum += matrix[i][j];
                }
                all += matrix[i][j];
            }
        }

        float result = (float)sum / (float)all;
        g2d.setColor(new Color(result, result, result));
        g2d.clearRect(0, 0, 600, 600);
        Rectangle2D.Double fill = new Rectangle2D.Double(0, 0, 600, 600);
        g2d.fill(fill);
        g2d.setColor(Color.BLACK);

        for (int i = 0; i < mLen+1; i++) {
            Line2D.Double vertical = new Line2D.Double(i*cellSize, 0, i*cellSize, cellSize*mLen);
            Line2D.Double horizontal = new Line2D.Double(0, i*cellSize, cellSize*mLen, i*cellSize);
            g2d.draw(vertical);
            g2d.draw(horizontal);
        }

        g2d.setColor(Color.RED);
        Line2D.Double line = new Line2D.Double(x1, y1, x2, y2);
        g2d.draw(line);

        String output = String.format("%d / %d", sum, all);
        g2d.drawString(output, 300, 300);

    }
}