/**********************
* Name: Darlene Zouras
* DOM and Events Assignment
* CS 290 Fall 2016
**********************/

// Create the table!
var newTable = document.createElement("table");
newTable.id = "newTable";
newTable.cellSpacing = "5px";
var topRow = document.createElement("tr");
newTable.appendChild(topRow);

// Create row of header cells
for (var i = 0; i < 4; i++) {
	var newHead = document.createElement("th");
	newHead.textContent = "Header " + i;
	newHead.style.border = "1px solid black";
	topRow.appendChild(newHead);
}
newTable.appendChild(topRow);

// Create the rest of the grid
for (var k = 1; k < 4; k++) {
	var newRow = document.createElement("tr");
	for (var j = 1; j < 5; j++) {
		var newCell = document.createElement("td");
		newCell.textContent = j + ", " + k;
		newCell.style.border = "1px solid black";
		newCell.style.padding = "3px";
		newCell.id = "cell-" + j + "-" + k;
		newRow.appendChild(newCell);
	}
	newTable.appendChild(newRow);
}

// create buttons
var markCell = document.createElement("button");
markCell.textContent = "Mark Cell";
markCell.id = "markCell";

var moveUp = document.createElement("button");
moveUp.textContent = "Move Up";
moveUp.id = "moveUp";

var moveDown = document.createElement("button");
moveDown.textContent = "Move Down";
moveDown.id = "moveDown";

var moveLeft = document.createElement("button");
moveLeft.textContent = "Move Left";
moveLeft.id = "moveLeft";

var moveRight = document.createElement("button");
moveRight.textContent = "Move Right";
moveRight.id = "moveRight";

newTable.children[1].children[0].style.border = "3px solid red";

// create table of direction buttons
var directTable = document.createElement("table");
directTable.style.border = "0px";
var dTopRow = document.createElement("tr");
var dTopLeft = document.createElement("td");
dTopRow.appendChild(dTopLeft);
var upCell = document.createElement("td");
upCell.appendChild(moveUp);
dTopRow.appendChild(upCell);
var dTopRight = document.createElement("td");
dTopRow.appendChild(dTopRight);
directTable.appendChild(dTopRow);

var dBottomRow = document.createElement("tr");
var leftCell = document.createElement("td");
leftCell.appendChild(moveLeft);
var downCell = document.createElement("td");
downCell.appendChild(moveDown);
var rightCell = document.createElement("td");
rightCell.appendChild(moveRight);
dBottomRow.appendChild(leftCell);
dBottomRow.appendChild(downCell);
dBottomRow.appendChild(rightCell);
directTable.appendChild(dBottomRow);

document.body.appendChild(newTable);
document.body.appendChild(directTable);
document.body.appendChild(markCell);

// Location the highlighted cell!
var x = 1;
var y = 1;
function getCell(x, y) {
	return document.getElementById("cell-" + x + "-" + y);
}
var cellSelect = getCell(x, y);

// button functionality
function changeColor() {
	cellSelect.style.backgroundColor = "yellow";
}
document.getElementById("markCell").addEventListener("click", changeColor);

function up() {
	if (y > 1) {
			cellSelect.style.border = "1px solid black";
			y--;
		}
	cellSelect = getCell(x, y);
	cellSelect.style.border = "3px solid red";
}
document.getElementById("moveUp").addEventListener("click", up);

function down() {
	if (y < 3) {
			cellSelect.style.border = "1px solid black";
			y++;
		}
	cellSelect = getCell(x, y);
	cellSelect.style.border = "3px solid red";
}
document.getElementById("moveDown").addEventListener("click", down);

function left() {
	if (x > 1) {
			cellSelect.style.border = "1px solid black";
			x--;
		}
	cellSelect = getCell(x, y);
	cellSelect.style.border = "3px solid red";
}
document.getElementById("moveLeft").addEventListener("click", left);

function right() {
	if (x < 4) {
			cellSelect.style.border = "1px solid black";
			x ++;
		}
	cellSelect = getCell(x, y);
	cellSelect.style.border = "3px solid red";
}
document.getElementById("moveRight").addEventListener("click", right);
