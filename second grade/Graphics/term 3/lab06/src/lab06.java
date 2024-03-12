import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.stage.Stage;

public class lab06 extends Application {
    //Constants
    private final int screen_width = 640;
    private final int screen_height = 480;
    private final int cell_size = 8;

    private final byte[][] shape = {//Исходные вершины фигуры
            {10, 13},
            {15, 25},
            {45, 45},
            {48, 22},
            {23, 12},
    };
    private final byte[][] hole = { //вершины отверстия
            {27, 17},
            {25, 24},
            {35, 27}
    };
    private final int[] startCord = {19, 18}; //координаты точки от которой начнется заполнение фигуры

    private final byte[][] fieldState = new byte[screen_width / cell_size][screen_height / cell_size];

    //Colors
    private final Paint background_color = Color.WHITE;
    private final Paint cell_1_color = Color.BLUE;
    private final Paint cell_2_color = Color.RED;

    @Override
    public void start(Stage stage) {
        initUI(stage);
    }

    private void initUI(Stage stage) {
        Pane root = new Pane();
        Canvas canvas = new Canvas(screen_width, screen_height);
        canvas.setScaleY(-1);
        GraphicsContext gc = canvas.getGraphicsContext2D();
        root.getChildren().add(canvas);
        Scene scene = new Scene(root, screen_width, screen_height, Color.WHITESMOKE);
        stage.setResizable(false);
        stage.setTitle("lab06");
        stage.setScene(scene);
        stage.show();
        new Thread(() -> {
            try {
                fillShape();
                drawHole();
                drawGrid(gc);
                updateField(gc);
                checkCellsNearby(gc, startCord[0], startCord[1]);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }).start();
    }

    private void fillShape() {
        for (int i = 0; i < shape.length - 1; i++) {
            drawDDA(shape[i][0], shape[i + 1][0], shape[i][1], shape[i + 1][1]);
        }
        drawDDA(shape[0][0], shape[shape.length - 1][0], shape[0][1], shape[shape.length - 1][1]);
    }
    private void drawHole() {
        for (int i = 0; i < hole.length - 1; i++) {
            drawDDA(hole[i][0], hole[i + 1][0], hole[i][1], hole[i + 1][1]);
        }
        drawDDA(hole[0][0], hole[hole.length - 1][0], hole[0][1], hole[hole.length - 1][1]);
    }

    private void drawGrid(GraphicsContext gc) {
        gc.setStroke(Color.BLACK);
        for (int i = 0; i <= screen_width / cell_size; i++) {
            gc.strokeLine(i * cell_size, 0, i * cell_size, screen_height);
        }
        for (int i = 0; i <= screen_height / cell_size; i++) {
            gc.strokeLine(0, i * cell_size, screen_width, i * cell_size);
        }
    }

    private void updateField(GraphicsContext gc) {
        for (int i = 0; i < fieldState.length; i++) {
            for (int j = 0; j < fieldState[i].length; j++) {
                fillCell(gc, i, j, fieldState[i][j]);
            }
        }
    }

    private void fillCell(GraphicsContext gc, int x, int y, byte color) {
        if (color == 1) {
            gc.setFill(cell_1_color);
        } else if (color == 2) {
            gc.setFill(cell_2_color);
        } else {
            gc.setFill(background_color);
        }
        gc.fillRect(x * cell_size + 1, y * cell_size + 1, cell_size - 2, cell_size - 2);
    }

    private void drawDDA(int x1, int x2, int y1, int y2) {
        double length = Math.max(Math.abs(x2 - x1), Math.abs(y2 - y1));
        double dx = (x2 - x1) / length;
        double dy = (y2 - y1) / length;
        double x = x1 + 0.5 * (dx >= 0 ? 1 : -1);
        double y = y1 + 0.5 * (dy >= 0 ? 1 : -1);
        for (int i = 0; i <= length; i++) {
            fieldState[(int) Math.floor(x)][(int) Math.floor(y)] = 2;
            x += dx;
            y += dy;
        }
    }

    private void checkCellsNearby(GraphicsContext gc, int x, int y) throws InterruptedException {
        fillCell(gc, x, y, (byte) 1);
        fieldState[x][y] = 1;
        Thread.sleep(30);
        byte border = 2;
        byte drawn = 1;
        if (fieldState[x + 1][y] != border && fieldState[x + 1][y] != drawn) {
            checkCellsNearby(gc, x + 1, y);
        }
        if (fieldState[x][y + 1] != border && fieldState[x][y + 1] != drawn) {
            checkCellsNearby(gc, x, y + 1);
        }
        if (fieldState[x - 1][y] != border && fieldState[x - 1][y] != drawn) {
            checkCellsNearby(gc, x - 1, y);
        }
        if (fieldState[x][y - 1] != border && fieldState[x][y - 1] != drawn) {
            checkCellsNearby(gc, x, y - 1);
        }
    }
    public static void main(String[] args) {
        launch(args);
    }
}