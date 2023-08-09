// ConsoleApplication18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*  HTML CODE GENERATOR FOR FOLLOWING GRAPH 

                         ypad
        (x1,y1)
          |                _ _     param data 
          |          _ _    |      variable data
          |           |     |
          |           |     |
          |           |     |
          |           |     |
          |           |     |
          |           *     _
          |           |     V
          |           O     |
 <xpad>   |           |     |
          |           +     |
          |           |     |
          |           |     |
          |           |     |
          |           |     |
          |          ---   ---
          |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _

       (ox,oy)                           (x2,y2)


       graph width

       Determine graph origin (ox,oy) and then compute everything relative to it.

*/

std::string styleBlock = R"html(
     <style>

        .iconsize {
            width: 24;
            height: 24;
        }

        .midiconsize {
            height: 48;
            width: 48;
        }

        .blueSymbol {
            border: 1px solid #4571c4;
            fill: #4571c4;
        }

        .greenSymbol {
            border: 1px solid green;
            fill: green;
        }

        .blueLineSymbol {
            stroke: #4571c4;
            stroke-width: 2;
        }

        .greenLineSymbol {
            stroke: green;
            stroke-width: 2;
        }

        .greybarSymbol {
            border: 1px solid black;
            fill: lightgrey;
            stroke-width: 1;
            stroke: rgb(0,0,0);
        }

        .darkgreybarSymbol {
            border: 1px solid black;
            fill: darkgray;
            stroke-width: 1;
            stroke: rgb(0,0,0);
        }

        td {
            padding-bottom: 25px;
            text-align:right;
            font-family:Calibri;
            font-size: 20px;
        }

        .names {
            font-weight: bold;
        }
    </style>
)html";

std::string svgdefinitions = R"html(
    <svg xmlns="http://www.w3.org/2000/svg" style="display:none">
        <symbol id="shapes-line" viewBox="0 0 8 8"> <line x1="0" y1="4" x2="8" y2="4" /> </symbol>
        <symbol id="shapes-triangle" viewBox="0 0 8 8"> <polygon points="4,1 7,7 1,7" /> </symbol>
        <symbol id="shapes-cross" viewBox="0 0 8 8"> <polygon points="2,1 4,3 6,1 7,2 5,4 7,6 6,7 4,5 2,7 1,6 3,4 1,2 " /> </symbol>
        <symbol id="shapes-plus" viewBox="0 0 8 8"> <polygon points="2,0 6,0 6,2 8,2 8,6 6,6 6,8 2,8 2,6 0,6 0,2 2,2" /> </symbol>
        <symbol id="shapes-circle" viewBox="0 0 8 8"> <circle cx="4" cy="4" r="4" /> </symbol>
        <symbol id="shapes-vbar" viewBox="0 0 20 60"> <rect width="20" height="60" /> </symbol>
    </svg>
)html";


std::string graphContent = R"html(
    <svg width="400" height="600" xmlns="http://www.w3.org/2000/svg"
                 xmlns:xlink="http://www.w3.org/1999/xlink">

                <!-- X and Y axis  -->
                <line class="line1" x1="30" y1="10" x2="30" y2="550" stroke="black" stroke-width="3" />
                <line x1="30" y1="550" x2="400" y2="550" stroke="black" stroke-width="3" />

                <!-- Legends on Y axis  -->
                <text x="0" y="450" fill="black" font-weight="bold">1.0</text>
                <text x="0" y="350" fill="black" font-weight="bold">1.5</text>
                <text x="0" y="250" fill="black" font-weight="bold">2.0</text>
                <text x="0" y="150" fill="black" font-weight="bold">2.5</text>
                <text x="0" y="50" fill="black" font-weight="bold">3.0</text>

                <!-- Reference lines parallel to X axis   -->
                <line x1="30" y1="450" x2="400" y2="450" stroke="black" stroke-width="1" />
                <line x1="30" y1="350" x2="400" y2="350" stroke="black" stroke-width="1" />
                <line x1="30" y1="250" x2="400" y2="250" stroke="black" stroke-width="1" />
                <line x1="30" y1="150" x2="400" y2="150" stroke="black" stroke-width="1" />
                <line x1="30" y1="50" x2="400" y2="50" stroke="black" stroke-width="1" />

                <!-- Delta Rectangles    -->
                <rect x="200" y="100" width="100" height="300" stroke="black" stroke-width="1" fill="grey" />
                <rect x="220" y="140" width="60" height="220" stroke="black" stroke-width="1" fill="#c9ffe5" />

                <!-- Parameter Min Max Line    -->
                <line x1="230" y1="70" x2="230" y2="430" stroke="black" stroke-width="1" />
                <line x1="225" y1="70" x2="235" y2="70" stroke="black" stroke-width="1" />
                <line x1="225" y1="430" x2="235" y2="430" stroke="black" stroke-width="1" />

                <!-- Variable Data Min Max Line    -->
                <line x1="260" y1="60" x2="260" y2="440" stroke="green" stroke-width="3" />
                <line x1="255" y1="60" x2="265" y2="60" stroke="green" stroke-width="3" />
                <line x1="255" y1="440" x2="265" y2="440" stroke="green" stroke-width="3" />

                <!-- min, max, mod, median symbols on graph  -->
                <svg x="248" y="270" width="25" height="25"> <use href="#shapes-triangle" class="greenSymbol" /> </svg>
                <svg x="218" y="220" width="25" height="25"> <use href="#shapes-plus" class="blueSymbol" /> </svg>
                <svg x="218" y="270" width="25" height="25"> <use href="#shapes-circle" class="blueSymbol" /> </svg>
                <svg x="218" y="320" width="25" height="25"> <use href="#shapes-cross" class="blueSymbol" /> </svg>

            </svg>
)html";

std::string LegendContent = R"html(
                <table>
                <tr>
                    <td><span class="names">Variable Data:</span></td>
                    <td><svg x="248" y="270" width="25" height="25"> <use href="#shapes-line" class="blueLineSymbol" /> </svg></td>
                </tr>
                <tr>
                    <td><span class="names">Mean:</span></td>
                    <td><svg x="248" y="270" width="25" height="25"> <use href="#shapes-circle" class="blueSymbol" /> </svg></td>
                </tr>
                <tr>
                    <td><span class="names">Median:</span></td>
                    <td style="text-align:right"><svg x="248" y="270" width="25" height="25"> <use href="#shapes-plus" class="blueSymbol" /> </svg></td>
                </tr>
                <tr>
                    <td><span class="names">Mode:</span></td>
                    <td><svg x="248" y="270" width="25" height="25"> <use href="#shapes-cross" class="blueSymbol" /> </svg></td>
                </tr>
                <tr>
                    <td><span class="names">+/-1&delta;: </span></td>
                    <td><svg x="248" y="270" width="25" height="25"> <use href="#shapes-vbar" class="greybarSymbol" /> </svg></td>
                </tr>
                <tr>
                    <td><span class="names">+/-2&delta;: </span></td>
                    <td><svg x="248" y="270" width="25" height="25"> <use href="#shapes-vbar" class="darkgreybarSymbol" /> </svg></td>
                </tr>
                <tr>
                    <td><span class="names">Parameter Data:</span></td>
                    <td><svg x="248" y="270" width="25" height="25"> <use href="#shapes-line" class="greenLineSymbol" /> </svg></td>
                </tr>
                <tr>
                    <td><span class="names">Goal:</span></td>
                    <td><svg x="248" y="270" width="25" height="25"> <use href="#shapes-triangle" class="greenSymbol" /> </svg></td>
                </tr>

            </table>
)html";


std::string docHeader = R"html(
<html>
<head>
<title>My SVG experiement</title>
)html";

std::string headCloseBodyOpen = R"html(
</head>
<body>
)html";

std::string tableOpen = R"html(
<table width="600">
        <td>
)html";

std::string tableClose = R"html(
        </td>
        </table>
)html";

std::string tableDataCloseDataOpen = R"html(
        </td>
        <td>
)html";

std::string bodyCloseDocClose = R"html(
        </body>
        </html>
)html";

std::string color1 = "#d6dce5";
std::string color2 = "#a5a5a5";

int graphWidth = 500;
int graphHeight = 500;
int xpad = 50;
int ypad = 50;
int svgWidth = graphWidth + xpad;
int svgHeight = graphHeight + ypad;

int ox = xpad;
int oy = ypad + graphHeight;
int x1 = xpad;
int yy1 = ypad;
int x2 = xpad + graphWidth;
int y2 = oy;

int margin = 5;
int num_steps = 6;
int step_size = graphHeight / (num_steps) - margin; 

int param_variable_gap = static_cast<int>(graphWidth * 0.05);  // gap between parameter line and variable line
int graphCenterX = xpad + graphWidth / 2;
int graphCenterY = ypad + graphHeight / 2;
int paramLine_X = graphCenterX + param_variable_gap/2;      // X position for Parameter graph 
int variableLine_X = graphCenterX - param_variable_gap/2;  // X position for Variable graph 
int delta1RectWidth = param_variable_gap * 2;             // 2 times  Delta 1 rectangle width 
int delta2RectWidth = param_variable_gap * 3;            // 3 times  Delta 2 rectangle width 
int delta1_X = graphCenterX - delta1RectWidth / 2;      // delta 1 rectangle x position 
int delta2_X = graphCenterX - delta2RectWidth / 2;     // delta 2 rectangle x position 

double param_min = 0.2;
double param_max = 3.4;
double param_goal = 1.8;

//Mean is the average value of the given observations
//Median is the middle value of the given observations   (will use this as center)
//Mode is the most repeated value in the given observation
double variable_min = 0.3;
double variable_max = 3.2;
double variable_range = abs(variable_max - variable_min);
double variable_mean = 2.4;
double variable_median = 2.1;
double variable_mode = 1.8;

int delta1RectHeight = static_cast<int>(graphHeight * .4);
int delta2RectHeight = static_cast<int>(graphHeight * .6);
int delta1_Y = graphCenterY - delta1RectHeight / 2;
int delta2_Y = graphCenterY - delta2RectHeight / 2;

int paramLineY1 = oy - graphHeight * .9;
int paramLineY2 = oy - graphHeight * .1;
int pCap = delta1RectWidth / 3;

int variableLineY1 = oy - graphHeight * .95;
int variableLineY2 = oy - graphHeight * .07;

double data_step = 0.5;
double data_start = 1.0;

int symbolWidth = 25;
int symbolHeight = 25;

double YMin = variable_min < param_min ? variable_min : param_min;
double YMax = variable_max > param_max ? variable_max : param_max;

int variableMeanYPosition = 10;
int variableMedianYPosition = 10;
int variableModeYPosition = 10;
int paramGoalYPosition = 10;

void initialiseData() {
    // Keep YMin and YMax 10% smaller and greater than input data. 
    YMin = YMin * 0.9;
    YMax = YMax * 1.1;
    double YRange = abs(YMax - YMin);
    variableMeanYPosition = static_cast<int> ((graphHeight * abs(variable_mean)) / YRange);
    variableMedianYPosition = static_cast<int> ((graphHeight * abs(variable_median)) / YRange);
    variableModeYPosition = static_cast<int> ((graphHeight * abs(variable_mode)) / YRange);
    paramGoalYPosition = static_cast<int> ((graphHeight * abs(param_goal)) / YRange);
}


std::string f(int v) {
    return std::to_string(v);
}

#include <sstream>
#include <iomanip>      // std::setprecision
std::string fd(double v) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << v;
    return ss.str();
}

std::string getTableOpenTag() {
    std::string tableOpen = "";
    tableOpen += "<table width=\"" + f(graphWidth*2) + "\">";
    tableOpen += "<td>";
    return tableOpen;
}

std::string computeGraph() {
    std::string s = "";
    s += "<svg width=\"" + f(svgWidth) + "\" height=\"" + f(svgHeight) + "\" xmlns=\"http://www.w3.org/2000/svg\"  xmlns:xlink=\"http://www.w3.org/1999/xlink\">";
    s += "<!-- X and Y axis  -->";
    s += "<line class=\"line1\" x1=\"" + f(x1) + "\" y1=\"" + f(yy1) + "\" x2=\"" + f(ox) + "\" y2=\"" + f(oy) + "\" stroke=\"black\" stroke-width=\"3\" />";
    s += "<line class=\"line1\" x1=\"" + f(x2) + "\" y1=\"" + f(y2) + "\" x2=\"" + f(ox) + "\" y2=\"" + f(oy) + "\" stroke=\"black\" stroke-width=\"3\" />";
    
    s += "<!-- Legends on Y axis  -->";
    int xpos = ox - xpad;
    for (int i = 1; i <= num_steps; i++) {
        int ypos = oy - (i * step_size);
        double value = data_start + i * data_step;
        s += "<text x=\"" + f(xpos) + "\" y=\"" + f(ypos) + "\" fill=\"black\" font-weight=\"bold\">" + fd(value) + "</text>";
        s += "<line x1=\"" + f(ox) + "\" y1=\"" + f(ypos) + "\" x2=\"" + f(x2) + "\" y2=\"" + f(ypos) + "\" stroke=\"black\" stroke-width=\"1\"/>";
    }

    s += "<!-- Delta Rectangles  -->";
    s += "<rect x=\"" + f(delta2_X) + "\" y=\"" + f(delta2_Y) + "\" width=\"" + f(delta2RectWidth) + "\" height=\"" + f(delta2RectHeight) + "\" stroke=\"black\" stroke-width=\"1\" fill=\"" + color2 + "\"/>";
    s += "<rect x=\"" + f(delta1_X) + "\" y=\"" + f(delta1_Y) + "\" width=\"" + f(delta1RectWidth) + "\" height=\"" + f(delta1RectHeight) + "\" stroke=\"black\" stroke-width=\"1\" fill=\"" + color1 + "\"/>";

    s += "<!-- Parameter Min Max Line  -->";
    s += "<line x1=\"" + f(paramLine_X) + "\" y1=\"" + f(paramLineY1) + "\" x2=\"" + f(paramLine_X) + "\" y2=\"" + f(paramLineY2) + "\" stroke=\"green\" stroke-width=\"2\"/>";
    s += "<line x1=\"" + f(paramLine_X-pCap) + "\" y1=\"" + f(paramLineY1) + "\" x2=\"" + f(paramLine_X+pCap) + "\" y2=\"" + f(paramLineY1) + "\" stroke=\"green\" stroke-width=\"2\"/>";
    s += "<line x1=\"" + f(paramLine_X-pCap) + "\" y1=\"" + f(paramLineY2) + "\" x2=\"" + f(paramLine_X+pCap) + "\" y2=\"" + f(paramLineY2) + "\" stroke=\"green\" stroke-width=\"2\"/>";

    s += "<!-- Variable Min Max Line  -->";
    s += "<line x1=\"" + f(variableLine_X) + "\" y1=\"" + f(variableLineY1) + "\" x2=\"" + f(variableLine_X) + "\" y2=\"" + f(variableLineY2) + "\" stroke=\"#4571c4\" stroke-width=\"2\"/>";
    s += "<line x1=\"" + f(variableLine_X - pCap) + "\" y1=\"" + f(variableLineY1) + "\" x2=\"" + f(variableLine_X + pCap) + "\" y2=\"" + f(variableLineY1) + "\" stroke=\"#4571c4\" stroke-width=\"2\"/>";
    s += "<line x1=\"" + f(variableLine_X - pCap) + "\" y1=\"" + f(variableLineY2) + "\" x2=\"" + f(variableLine_X + pCap) + "\" y2=\"" + f(variableLineY2) + "\" stroke=\"#4571c4\" stroke-width=\"2\"/>";

    s += "<svg x=\"" + f(paramLine_X - symbolWidth/2) + "\" y=\"" + f(paramGoalYPosition) + "\" width=\"" + f(symbolWidth) + "\" height=\"" + f(symbolHeight) + "\">" + "<use href=\"#shapes-triangle\" class=\"greenSymbol\"/></svg>";
    s += "<svg x=\"" + f(variableLine_X - symbolWidth / 2) + "\" y=\"" + f(variableMeanYPosition) + "\" width=\"" + f(symbolWidth) + "\" height=\"" + f(symbolHeight) + "\">" + "<use href=\"#shapes-circle\" class=\"blueSymbol\"/></svg>";
    s += "<svg x=\"" + f(variableLine_X - symbolWidth / 2) + "\" y=\"" + f(variableMedianYPosition) + "\" width=\"" + f(symbolWidth) + "\" height=\"" + f(symbolHeight) + "\">" + "<use href=\"#shapes-plus\" class=\"blueSymbol\"/></svg>";
    s += "<svg x=\"" + f(variableLine_X - symbolWidth / 2) + "\" y=\"" + f(variableModeYPosition) + "\" width=\"" + f(symbolWidth) + "\" height=\"" + f(symbolHeight) + "\">" + "<use href=\"#shapes-cross\" class=\"blueSymbol\"/></svg>";

    return s;
}

int main()
{
    initialiseData();

    std::string doc;
    doc += docHeader;
    doc += styleBlock;
    doc += headCloseBodyOpen;
    doc += svgdefinitions;
    doc += getTableOpenTag();
    doc += computeGraph();
    doc += tableDataCloseDataOpen;
    doc += LegendContent;
    doc += tableClose;
    doc += bodyCloseDocClose;


    std::ofstream out("D:\\output.html");
    out << doc;
    out.close();

}

