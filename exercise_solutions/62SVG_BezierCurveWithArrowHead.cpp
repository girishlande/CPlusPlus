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
double arrowlength = 10;

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


Point2D getVector(Point2D p1, Point2D p2) {
    return { p2.x - p1.x, p2.y - p1.y };
}

Point2D normalize(Point2D v) {
    double length = sqrt(v.x * v.x + v.y * v.y);
    v.x = v.x / length;
    v.y = v.y / length;
    return { v.x, v.y };
}

Point2D giveLengthToVector(Point2D v, double length) {
    v.x = v.x * length;
    v.y = v.y * length;
    return v;
}

Point2D getNewPoint(Point2D vec, Point2D point) {
    return { point.x + vec.x,point.y + vec.y };
}

Point2D negateVector(Point2D vec) {
    return { -vec.x,-vec.y };
}

Point2D rotateVector(Point2D vec, double ang) {
    double pi = 22.0 / 7;
    ang = ang * (pi / 180);
    return { vec.x * cos(ang) - vec.y * sin(ang),
              vec.x * sin(ang) + vec.y * cos(ang) };
}

string createArrowDir(double x1, double y1, double x2, double y2, std::string & color) {
    string gs("");
    double crossLength = arrowlength;
    Point2D p1{ x1,y1 };
    Point2D p2{ x2,y2 };
    Point2D vec = getVector(p1, p2);
    vec = normalize(vec);
    int angle = 20;
    vec = rotateVector(vec, angle);
    Point2D unitvec = { vec.x, vec.y };
    vec = giveLengthToVector(vec, crossLength);
    Point2D c1 = getNewPoint(vec, p1);
    vec = negateVector(vec);
    Point2D c2 = getNewPoint(vec, p1);

    vec = unitvec;
    vec = rotateVector(vec, (180-2*angle));
    vec = giveLengthToVector(vec, crossLength);
    Point2D c3 = getNewPoint(vec, p1);
    vec = negateVector(vec);
    Point2D c4 = getNewPoint(vec, p1);

    gs += "<polygon points = \"" + fd(x1) + " " + fd(y1) + " " + fd(c4.x) + " " + fd(c4.y) + " " + fd(c1.x) + " " + fd(c1.y) + "\" style =\"fill:" + color + "\"/>";

    // debug code
    //gs += "<line x1=\"" + fd(x1) + "\" y1=\"" + fd(y1) + "\" x2=\"" + fd(c4.x) + "\" y2=\"" + fd(c4.y) + "\" style=\"stroke:rgb(0,255,0);stroke-width:0.5\"/>";
    //gs += "<line x1=\"" + fd(x1) + "\" y1=\"" + fd(y1) + "\" x2=\"" + fd(c1.x) + "\" y2=\"" + fd(c1.y) + "\" style=\"stroke:rgb(0,255,0);stroke-width:0.5\"/>";
    //gs += "<line x1=\"" + fd(x1) + "\" y1=\"" + fd(y1) + "\" x2=\"" + fd(x2) + "\" y2=\"" + fd(y2) + "\" style=\"stroke:rgb(0,255,0);stroke-width:0.5\"/>";
    //gs += "\n<circle cx=\"" + fd(x2) + "\" cy=\"" + fd(y2) + "\" r=\"0.5\" stroke=\"red\" stroke-width=\"0.5\" fill=\"pink\" />";

    return gs;
}

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

Point2D pointAtDistance(double dist, Point2D p1, Point2D p2, Point2D p3, Point2D p4) {
    double t = 0.0;
    double inc = 0.001;
    double sum = 0;
    Point2D p = p1;
    while (sum < dist) {
        t = t + inc;
        double px = bezierPoint(t, p1.x, p2.x, p3.x, p4.x);
        double py = bezierPoint(t, p1.y, p2.y, p3.y, p4.y);
        double d = distance(p.x, p.y, px, py);
        sum = sum + d;
        p = Point2D{ px,py };
    }
    return p;
}

// Create SVG Bezier curve from P1 to P4
std::string createSVGCurve(Point2D p1, Point2D p2, Point2D p3, Point2D p4, std::string& color) {
    std::string s("");
    std::vector<Point2D> v;
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    // Create SVG curve 
    s += "<path d=\"M" + fd(p1.x) + " " + fd(p1.y);
    s += " C";
    for (auto a : v) {
        s += " " + fd(a.x) + " " + fd(a.y);
    }
    s += "\" stroke=\"" + color + "\" stroke-width=\"1\" fill=\"none\"/>";

    bool drawControlPoints = false;
    if (drawControlPoints) {
        // Draw control points of the bezier curve 
        s += "\n<circle cx=\"" + fd(p1.x) + "\" cy=\"" + fd(p1.y) + "\" r=\"4\" stroke=\"black\" stroke-width=\"1\" fill=\"red\" />";
        for (auto a : v) {
            s += "\n<circle cx=\"" + fd(a.x) + "\" cy=\"" + fd(a.y) + "\" r=\"4\" stroke=\"black\" stroke-width=\"1\" fill=\"red\" />";
        }
    }

    bool drawArrowHead = true;
    if (drawArrowHead) {
        // Interpolate Point on curve and use it to draw arrow 
        Point2D p = pointAtDistance(arrowlength, p4, p3, p2, p1);
        s += createArrowDir(p4.x, p4.y, p.x, p.y, color);
    }
    
    bool drawInterpolatedPoints = false;
    if (drawInterpolatedPoints) {
        // Draw interpolated points on the bezier curve 
        double inc = 0.005;
        for (double t = inc; t < 1; t += inc) {
            double px = bezierPoint(t, p1.x, p2.x, p3.x, p4.x);
            double py = bezierPoint(t, p1.y, p2.y, p3.y, p4.y);
            s += "\n<circle cx=\"" + fd(px) + "\" cy=\"" + fd(py) + "\" r=\"0.2\" stroke=\"pink\" stroke-width=\"0.2\" fill=\"pink\" />";
        }
    }
    return s;
}

std::string computeGraph() {
    std::string s = "";
    s += "<svg width=\"" + f(svgWidth) + "\" height=\"" + f(svgHeight) + "\" xmlns=\"http://www.w3.org/2000/svg\"  xmlns:xlink=\"http://www.w3.org/1999/xlink\">";
    s += "\n";

    // Draw bezier curve using SVG path element 
    std::vector<Point2D> v;
    Point2D p1{ 400,10 };
    Point2D p2{ 400,400 }; v.push_back(p2);
    Point2D p3{ 140,10 }; v.push_back(p3);
    Point2D p4{ 100,400 }; v.push_back(p4);
    
    /*Point2D p1{ 100,100 };
    Point2D p2{ 100,200 }; v.push_back(p2);
    Point2D p3{ 400,200 }; v.push_back(p3);
    Point2D p4{ 400,100 }; v.push_back(p4);*/

    std::string col("#0000FF");
    s += createSVGCurve(p1, p2, p3, p4, col);

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

