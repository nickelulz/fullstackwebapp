const BACKEND_URL = 'http://localhost:3001'
const FRONTEND_SERVER_URL = 'http://localhost:3000'

const backend_submit_button = document.getElementById('backend_submit_button');
backend_submit_button.addEventListener('click', basic_text_backend_req);

function basic_text_backend_req() {
  // build data
  let message_raw = document.getElementById('backend_input').value;
  let json = `{"ip":"${getUserIP()}","text":"${message_raw}"}`;
  console.log('Attempting to send JOSN ' + json + ' to backend.');
  let status = backend_submit('/simple_test', json);
  // unsuccessful
  if (status < 200 || status >= 300)
    console.error('Could not submit to backend successfully.');
}

function getUserIP() {
  let req = new XMLHttpRequest();
  req.open('GET', FRONTEND_SERVER_URL + '/get-ip');
  req.send(null);
  console.log('Retrieving Connection IP: ' + req.status);
  return req.responseText;
}

function backend_submit(endpoint, json) {
  if (typeof endpoint != 'string')
    throw 'Backend endpoint type mismatch! Could not send data to backend due to typeof endpoint not being type string.';

  // request
  let req = new XMLHttpRequest();
  req.open('POST', BACKEND_URL + endpoint);
  req.setRequestHeader("Accept", "application/json");
  req.setRequestHeader("Content-Type", "application/json");
  console.log('Data submit to backend on endpoint ' + endpoint + ' status: ' + req.status);

  // send data
  req.send(json);
  return req.responseText;
}
