#include "FlightMap.h"

using namespace std;

void Map::addMarker(Location& location, Airport& airport) {
    html = html.substr(0, html.size() - 9);
    html += "            var marker_e0c37810ae724441860d1be45319756d = L.marker(\n"
          "                [" + to_string(location.getLatitude()) + ", " + to_string(location.getLongitude()) + "],\n"
          "                {}\n"
          "            ).addTo(map_5c9a6b2e6ab4426ab58e897091b2188b);"
          "            var icon_338382f8ccf9444a81c0d91703249644 = L.AwesomeMarkers.icon(\n"
          "                {\"extraClasses\": \"fa-rotate-0\", \"icon\": \"plane\", \"iconColor\": \"white\", \"markerColor\": \"green\", \"prefix\": \"fa\"}\n"
          "            );\n"
          "            marker_e0c37810ae724441860d1be45319756d.setIcon(icon_338382f8ccf9444a81c0d91703249644);\n"
          "        var popup_ddd224e1958240acbb614d6051d567b0 = L.popup({\"maxWidth\": \"100%\"});"
          "            var html_c7f4658d577c40f5b2e4c0c28d68cb3a = $(`<div id=\"html_c7f4658d577c40f5b2e4c0c28d68cb3a\" style=\"width: 100.0%; height: 100.0%;\">" + airport.getName() + "</div>`)[0];\n""            popup_ddd224e1958240acbb614d6051d567b0.setContent(html_c7f4658d577c40f5b2e4c0c28d68cb3a)\n;"
          "        marker_e0c37810ae724441860d1be45319756d.bindPopup(popup_ddd224e1958240acbb614d6051d567b0)\n"
          "        ;\n"
          "</script>";
}

void Map::addRoute(Location& location1, Location& location2) {
    html = html.substr(0, html.size() - 9);
    html += "   var poly_line_244a7d418bd1460fbcf5aad1bf6757c9 = L.polyline(\n"
          "       [[" + to_string(location1.getLatitude()) + ", " + to_string(location1.getLongitude()) + "], [" + to_string(location2.getLatitude()) + ", " + to_string(location2.getLongitude()) + "]],\n"
          "       {\"bubblingMouseEvents\": true, \"color\": \"#3388ff\", \"dashArray\": null, \"dashOffset\": null, \"fill\": false, \"fillColor\": \"#3388ff\", \"fillOpacity\": 0.2, \"fillRule\": \"evenodd\", \"lineCap\": \"round\", \"lineJoin\": \"round\", \"noClip\": false, \"opacity\": 1.0, \"smoothFactor\": 1.0, \"stroke\": true, \"weight\": 3}\n"
          "   ).addTo(map_5c9a6b2e6ab4426ab58e897091b2188b);\n"
          "</script>";
}

std::string Map::getHTML() {
    return html;
}

void Map::airportsurroundMap(Location &location, string name, string type) {
    html = html.substr(0, html.size() - 9);
    if (type == "Airport") {

    }
    else if (type == "Bus") {

    }
    else if (type == "Underground") {

    }
    else if (type == "Train") {

    }
    else {
        throw ("Invalid Duration"); /* fix this exception */
    }
    html += "            var marker_e0c37810ae724441860d1be45319756d = L.marker(\n"
            "                [" + to_string(location.getLatitude()) + ", " + to_string(location.getLongitude()) + "],\n"
            "                {}\n"
            "            ).addTo(map_5c9a6b2e6ab4426ab58e897091b2188b);"
            "            var icon_338382f8ccf9444a81c0d91703249644 = L.AwesomeMarkers.icon(\n"
            "                {\"extraClasses\": \"fa-rotate-0\", \"icon\": \"plane\", \"iconColor\": \"white\", \"markerColor\": \"green\", \"prefix\": \"fa\"}\n"
            "            );\n"
            "            marker_e0c37810ae724441860d1be45319756d.setIcon(icon_338382f8ccf9444a81c0d91703249644);\n"
            "        var popup_ddd224e1958240acbb614d6051d567b0 = L.popup({\"maxWidth\": \"100%\"});"
            "            var html_c7f4658d577c40f5b2e4c0c28d68cb3a = $(`<div id=\"html_c7f4658d577c40f5b2e4c0c28d68cb3a\" style=\"width: 100.0%; height: 100.0%;\">" + airport.getName() + "</div>`)[0];\n""            popup_ddd224e1958240acbb614d6051d567b0.setContent(html_c7f4658d577c40f5b2e4c0c28d68cb3a)\n;"
            "        marker_e0c37810ae724441860d1be45319756d.bindPopup(popup_ddd224e1958240acbb614d6051d567b0)\n"
            "        ;\n"
            "</script>";
}
