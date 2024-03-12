import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Buttons extends JPanel {
    private JButton dda;
    private JButton brasenham;
    private JButton trueSegment;
    private JButton lab02;
    private DrawingComponent drawingComponent;

    public Buttons(DrawingComponent dc) {
        dda = new JButton("Lab01 DDA");
        brasenham = new JButton("Lab01 Brasenham");
        trueSegment = new JButton("Lab01 True segment");
        lab02 = new JButton("Lab02");
        drawingComponent = dc;
    }

    public void setUpLabs() {
        setLayout(new GridLayout(2, 3));
        add(dda);
        add(brasenham);
        add(trueSegment);
        add(lab02);
        ButtonListener buttonListener = new ButtonListener();
        dda.addActionListener(buttonListener);
        brasenham.addActionListener(buttonListener);
        trueSegment.addActionListener(buttonListener);
        lab02.addActionListener(buttonListener);
    }

    private class ButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent ae) {
            Object o = ae.getSource();
            if (o == dda) {
                drawingComponent.setMethod(1);

            } else if (o == brasenham) {
                drawingComponent.setMethod(2);

            } else if (o == trueSegment) {
                drawingComponent.setMethod(3);

            } else if (o == lab02) {
                drawingComponent.setMethod(4);
            }
            drawingComponent.repaint();
        }
    }
}
