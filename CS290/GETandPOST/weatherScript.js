// Darlene Zouras
// CS 290 Fall 2016
// AJAX Interactions

var apiKey = "d41079176bed81eee77dc6a4b5a4ce23";

document.addEventListener('DOMContentLoaded', bindButtons);

function bindButtons() {
    document.getElementById('zipSubmit').addEventListener('click', function(event) {
        var req = new XMLHttpRequest();
        var zip = document.getElementById("zipcode").value;

        req.open('GET', "http://api.openweathermap.org/data/2.5/weather?zip=" + zip + ",us&appid=" + apiKey, true);

        req.addEventListener('load', function() {
            if (req.status >= 200 && req.status < 400) {
                var response = JSON.parse(req.responseText);

                document.getElementById('header').textContent = "Weather in your city: " + response.name;

                function kToF(k) {
                    f = (k * (9/5) - 459.67);
                    return f.toFixed(1);
                }

                document.getElementById('currentTemp').textContent = "Current Temperature: " + kToF(response.main.temp) + " F";
                document.getElementById('currentHumidity').textContent = "Current Humidity: " + response.main.humidity + "%";
            }
            else {
                console.log("Error in network request: " + request.statusText);
            }
        });

        req.send(null);
        event.preventDefault();
    })
}
