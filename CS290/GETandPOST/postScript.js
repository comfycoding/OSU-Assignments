// Darlene Zouras
// CS 290 Fall 2016
// AJAX Interactions

document.addEventListener('DOMContentLoaded', bindButtons1);

function bindButtons1() {
    document.getElementById('postSubmit').addEventListener('click', function(event) {
        var req = new XMLHttpRequest();

        var payload = {textEntry:null};
        payload.textEntry = document.getElementById('textEntry').value;
        req.open('POST', 'http://httpbin.org/post', true);
        req.setRequestHeader('Content-type', 'application/json');

        req.addEventListener('load', function() {
            if(req.status >= 200 && req.status < 400) {
                var response = JSON.parse(req.responseText);

                document.getElementById('postHeader').textContent = "This is the text submitted: ";

                document.getElementById('returnText').textContent = response.data;
            }

            else {
                console.log("Error in network request: " + req.responseText.data.text);
            }
        });

        req.send(JSON.stringify(payload));
        event.preventDefault();
    });
}
