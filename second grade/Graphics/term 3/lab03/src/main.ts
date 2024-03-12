import p5 from 'p5';
import {Line, Polygon, Vector} from "./types";

const cellSize = 35;

declare global {
  interface Array<T> {
    last(): T;
    first(): T;
  }
}

Array.prototype.last = function () {
  return this[this.length - 1];
};

Array.prototype.first = function () {
  return this[0];
};

const CURRENT_SHAPE: Vector[] = [];

const stick = (val: number, acc = cellSize / 5) => val - val % acc;


const drawPoints = (p: p5, polygon: Polygon, multiplier = cellSize, color = 'black') => polygon.forEach(([x, y]) => {
  p.stroke(color);
  p.strokeWeight(3);
  p.point(x * multiplier, y * multiplier);
});

const drawBorders = (p: p5, polygon: Polygon, multiplier = cellSize) => {
  p.stroke('black');
  p.strokeWeight(1.5);
  for (let i = 0; i < polygon.length; i++) {
    const [x1, y1] = polygon[i];
    const [x2, y2] = polygon[(i + 1) % polygon.length];

    p.line(x1 * multiplier, y1 * multiplier, x2 * multiplier, y2 * multiplier);
  }
};

const intersectsRow = (
  rowY: number,
  rowLength: number,
  line: Line,
): boolean => {
  const x1 = 0;
  const [[x3, y3], [x4, y4]] = line;
  const t =
    ((x1 - x3) * (y3 - y4) - (rowY - y3) * (x3 - x4)) / ((x1 - rowLength) * (y3 - y4) - (rowY - rowY) * (x3 - x4));
  const u =
    ((x1 - x3) * (rowY - rowY) - (rowY - y3) * (x1 - rowLength)) / ((x1 - rowLength) * (y3 - y4) - (rowY - rowY) * (x3 - x4));

  return t >= 0 && t <= 1 && u >= 0 && u <= 1;
};

const getIntersectionPoint = (
  rowY: number,
  rowLength: number,
  line: Line,
): Vector => {
  const x1 = 0;
  const [[x3, y3], [x4, y4]] = line;
  const t =
    ((x1 - x3) * (y3 - y4) - (rowY - y3) * (x3 - x4)) / ((x1 - rowLength) * (y3 - y4) - (rowY - rowY) * (x3 - x4));
  const x = t * rowLength;

  return [x, rowY];
};

const getIntersectionPoints = (
  points: Array<Array<number>>,
  start: number,
  end: number,
  step: number,
  rowLength: number,
  cellSize: number,
): Polygon => {
  let intersectionPoints: Vector[] = [];
  const lines: Line[] = [];
  for (let i = 0; i < points.length - 1; i++) {
    {
      lines.push(
        [
          [
            points[i][0] * cellSize,
            points[i][1] * cellSize,
          ],
          [
            points[i + 1][0] * cellSize,
            points[i + 1][1] * cellSize,
          ],
        ],
      );
    }
    lines.push(
      [
        [
          points.first()[0] * cellSize,
          points.first()[1] * cellSize,
        ],
        [
          points.last()[0] * cellSize,
          points.last()[1] * cellSize,
        ],
      ],
    );
    let previousIndex: number;
    let nextIndex: number;
    for (const line of lines) {
      for (let row = start; row < end; row += step) {

        if (intersectsRow(row, rowLength, line)) {
          const intersectedPoint = getIntersectionPoint(
            row,
            rowLength,
            line,
          );
          intersectionPoints.push(intersectedPoint);
        }
      }
    }

    for (let index = 0; index < points.length; index++) {
      switch (index) {
        case 0: {
          previousIndex = points.length - 1;
          nextIndex = index + 1;
          break;
        }
        case points.length - 1: {
          nextIndex = 0;
          previousIndex = index - 1;
          break;
        }
        default: {
          nextIndex = index + 1;
          previousIndex = index - 1;
          break;
        }
      }
      if ((points[index][1] * cellSize > points[previousIndex][1] * cellSize && points[index][1] * cellSize > points[nextIndex][1] * cellSize) ||
        (points[index][1] * cellSize < points[previousIndex][1] * cellSize && points[index][1] * cellSize < points[nextIndex][1] * cellSize)
      ) intersectionPoints = intersectionPoints.filter((it) => it[0] !== points[index][0] * cellSize || it[1] !== points[index][1] * cellSize);
    }
  }

  return intersectionPoints;
};

const getRows = (
  points: Array<Array<number>>,
): Array<number> => {
  const rows: number[] = [];
  let row = 0;
  for (const point of points) {
    if (point[1] != row) {
      row = point[1];
      if (!rows.includes(row)) {
        rows.push(row);
      }
    }
  }
  return rows;
};

const findInArray = (
  point: Array<number>,
  points: Array<Array<number>>,
): boolean => {
  for (const i of points) {
    if (point[0] == i[0] && point[1] == i[1]) return true;
  }
  return false;
};

let end = false;

new p5((p: p5) => {
  p.setup = () => {
    p.createCanvas(600.5, 600.5);
  };

  p.draw = async () => {
    p.clear();
    const {width, height} = p;

    p.stroke(0);
    p.strokeWeight(1);
    //drawing a grid
    for (let i = 0; i < width / cellSize; i++) {
      p.line(
        i * cellSize, 0,
        i * cellSize, height,
      );
    }
    for (let i = 0; i < height / cellSize; i++) {
      p.line(
        0, i * cellSize,
        width, i * cellSize,
      );
    }
    drawBorders(p, CURRENT_SHAPE);
    drawPoints(p, CURRENT_SHAPE);
    if (end) {
      p.noLoop();

      const intersectionPoints = getIntersectionPoints(CURRENT_SHAPE, 0, height, cellSize / 5, width, cellSize);
      drawPoints(p, intersectionPoints, 1, 'red');
      const rows = getRows(intersectionPoints);
      rows.sort((a, b) => a - b);
      for await (const row of rows) {
        const rowPoints = [] as Vector[];
        for (const point of intersectionPoints) {
          if (point[1] == row && !findInArray(point, rowPoints)) {
            rowPoints.push(point);
          }
        }
        rowPoints.sort((a, b) => a[0] - b[0]);

        p.strokeWeight(1);
        if (rowPoints.length == 2) {
          p.line(
            ...rowPoints[0],
            ...rowPoints[1],
          );
        } else if (rowPoints.length == 4) {
          p.line(
            ...rowPoints[0],
            ...rowPoints[1],
          );
          p.line(
            ...rowPoints[2],
            ...rowPoints[3],
          );
        } else if (rowPoints.length == 6) {
          p.line(
            ...rowPoints[0],
            ...rowPoints[1],
          );
          p.line(
            ...rowPoints[2],
            ...rowPoints[3],
          );
          p.line(
            ...rowPoints[4],
            ...rowPoints[5],
          );
        }

        await (new Promise((resolve) => setTimeout(resolve, 1000)));
      }
    } else {
      const [x, y] = [p.mouseX, p.mouseY].map((v) => stick(v));

      p.strokeWeight(10);
      p.stroke('black');
      p.point(x, y);
    }

  };

  p.mousePressed = () => {
    const [x, y] = [p.mouseX, p.mouseY]
      .map((v) => stick(v))
      .map((v) => v / cellSize);

    CURRENT_SHAPE.push([x, y]);
  };

  p.keyPressed = () => {
    end = true;
  };
});
