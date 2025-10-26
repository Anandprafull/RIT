const http = require("http");
const server = http.createServer((req, res) => {
  res.writeHead(200, { "Content-Type": "text/plain" });
  const path = req.url;
  if (path === "/") {
    res.end("Hello, Node.js!");
  } else if (path === "/about") {
    res.end("About Us");
  } else if (path === "/contact") {
    res.end("Contact Us");
  } else {
    res.writeHead(404, { "Content-Type": "text/plain" });
    res.end("404 Not Found");
  }
}).listen(3000, () => {
  console.log("Server running at http://localhost:3000/");
});
