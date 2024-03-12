var canvas = document.getElementById('poly');
var context = canvas.getContext('2d');

var flag = 0;
var start = 1;
var draw_ab = 0;
var draw_poly = 0;
var x_begin, y_begin;
var ab;
var x_coords = [];
var y_coords = [];

var idata = context.getImageData(0, 0, canvas.width, canvas.height);
console.log(idata);

canvas.addEventListener("click", function(event){
	if(start == 1){
		if (!flag) {
			x0 = event.offsetX;
			y0 = event.offsetY;
			x_coords.push(x0);
			y_coords.push(y0);
			flag = 1;
			x_begin = x0;
			y_begin = y0;
		} else {
			x1 = event.offsetX;
			y1 = event.offsetY;
			x_coords.push(x1);
			y_coords.push(y1);
			drawLine(x0, y0, x1, y1);
			flag = 0;
			start = 0;
			draw_poly = 1;
		}
	}
	if(draw_poly == 1){
		x0 = x1;
		y0 = y1;
		x1 = event.offsetX;
        y1 = event.offsetY;
		x_coords.push(x1);
		y_coords.push(y1);
        drawLine(x0, y0, x1, y1);
	}
	if(draw_ab == 1){
		if (!flag) {
			p1x = event.offsetX;
			p1y = event.offsetY;
			flag = 1;
        } else {
			p2x = event.offsetX;
			p2y = event.offsetY;
			flag = 0;
			drawLine(p1x, p1y, p2x, p2y);
			var state = 0;
		for(let i = 0; i < x_coords.length; i++){
			ax = x_coords[i];
			ay = y_coords[i];
			bx = x_coords[(i + 1) % x_coords.length];
			by = y_coords[(i + 1) % y_coords.length];
			var t = ( (p1y-p2y)*(ax-p1x)+(p2x-p1x)*(ay-p1y) ) / ( (bx-ax)*(p2y-p1y)+(by-ay)*(p1x-p2x) );
			if (t<=1 && t>=0) {
				if (state == 0){
					var ex = (bx-ax)*t+ax;
					var ey = (by-ay)*t+ay;
					state = 1;
					continue;
				}
				
				if (state == 1){
					ux = (bx-ax)*t+ax;
					uy = (by-ay)*t+ay;
					context.fillStyle = "#00ff00";
					drawLine(ex, ey, ux, uy); 
					context.fillStyle = "#000000";
					state = 0;
				}
			}
		}
              }
	}
});

canvas.addEventListener("dblclick", function(event){
	drawLine(x1, y1, x_begin, y_begin);
	draw_poly = 0;
	draw_ab = 1;
});

function drawLine(Xd, Yd, Xf, Yf){
	var Dx,Dy,Dx2,Dy2,Dxy,S;
	var Xinc,Yinc,X,Y;
	var col, i;
	col = 5;
	if (Xd < Xf) Xinc = 1; else Xinc = -1;
	if (Yd < Yf) Yinc = 1; else Yinc = -1;
	Dx = Math.abs(Xd - Xf);
	Dy = Math.abs(Yd - Yf);
	Dx2 = Dx + Dx; Dy2 = Dy + Dy;
	X = Xd; Y = Yd;
		if (Dx > Dy){
		S = Dy2 - Dx;
		Dxy = Dy2 - Dx2;
		for (i=0; i < Dx; i++){
			if (S >= 0){
				Y = Y + Yinc;
				S = S + Dxy;
			} else S = S + Dy2;
			X = X + Xinc;
			context.fillRect(X,Y,5,5);
		}
	}
	else{
		S = Dx2 - Dy;
		Dxy = Dx2 - Dy2;
		for (i=0; i < Dy; i++){
			if ( S >= 0){
				X = X + Xinc;
				S = S + Dxy;
			} else S = S + Dx2;
			Y = Y + Yinc;
			context.fillRect(X,Y,5,5);
		}
	}
}