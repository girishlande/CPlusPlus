// ConsoleApplication18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

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



std::string docHeader = R"html(
<html>
<head>
<title>My SVG experiement</title>
)html";

std::string headCloseBodyOpen = R"html(
</head>
<body>
)html";

std::string bodyCloseDocClose = R"html(
        </body>
        </html>
)html";

std::string color1 = "#d6dce5";
std::string color2 = "#a5a5a5";

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

int svgWidth = 800;
int svgHeight = 800;

struct Point2D {
    double x;
    double y;
};

double bezierPoint(double t, double a, double b, double c, double d)
{
    double C1 = (d - (3.0 * c) + (3.0 * b) - a);
    double C2 = ((3.0 * c) - (6.0 * b) + (3.0 * a));
    double C3 = ((3.0 * b) - (3.0 * a));
    double C4 = (a);
    return (C1 * t * t * t + C2 * t * t + C3 * t + C4);
}

std::string computeGraph() {
    std::string s = "";
    s += "<svg width=\"" + f(svgWidth) + "\" height=\"" + f(svgHeight) + "\" xmlns=\"http://www.w3.org/2000/svg\"  xmlns:xlink=\"http://www.w3.org/1999/xlink\">";
    s += "\n";

    // Draw bezier curve using SVG path element 
    std::vector<Point2D> v;
    Point2D p1{ 400,10 }; 
    Point2D p2{ 400,400 }; v.push_back(p2);
    Point2D p3{ 100,10 }; v.push_back(p3);
    Point2D p4{ 100,400 }; v.push_back(p4);
    s += "<path d=\"M" + f(p1.x) + " " + f(p1.y);
    s += " C";
    for (auto a : v) {
        s += " " + f(a.x) + " " + f(a.y);
    }
    s += "\" stroke=\"#0000FF\" stroke-width=\"2\" fill=\"none\"/>";

    // Draw control points of the bezier curve 
    s += "\n<circle cx=\"" + f(p1.x) + "\" cy=\"" + f(p1.y) + "\" r=\"4\" stroke=\"black\" stroke-width=\"1\" fill=\"red\" />";
    for (auto a : v) {
        s += "\n<circle cx=\"" + f(a.x) + "\" cy=\"" + f(a.y) + "\" r=\"4\" stroke=\"black\" stroke-width=\"1\" fill=\"red\" />";
    }

    // Draw interpolated points on the bezier curve 
    double inc = 0.02;
    for (double t = inc; t < 1; t += inc) {
        double px = bezierPoint(t, p1.x, p2.x, p3.x, p4.x);
        double py = bezierPoint(t, p1.y, p2.y, p3.y, p4.y);
        s += "\n<circle cx=\"" + f(px) + "\" cy=\"" + f(py) + "\" r=\"3\" stroke=\"black\" stroke-width=\"1\" fill=\"green\" />";
    }



    return s;
}

int main()
{

    std::string doc;
    doc += docHeader;
    doc += styleBlock;
    doc += headCloseBodyOpen;
    doc += svgdefinitions;
    doc += computeGraph();
    doc += bodyCloseDocClose;

    std::ofstream out("D:\\output.html");
    out << doc;
    out.close();

}

