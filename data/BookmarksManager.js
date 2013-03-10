
self.port.on("SendBookMarks", function(text) {
            console.log("self.port.on SendBookMarks=" + text);
            var event = document.createEvent('CustomEvent');
            event.initCustomEvent("SendBookMarks", true, true, text);
            document.documentElement.dispatchEvent(event);
        });

document.documentElement.addEventListener("RequesBookMarks", function(event) {
  console.log("RequesBookMarks=" + event.detail);
  self.port.emit("RequesBookMarks", event.detail);
  
}, false);


document.documentElement.addEventListener("StoreData", function(event) {
  console.log("StoreData=" + event.detail);
  self.port.emit("StoreData", event.detail);
  
}, false);

document.documentElement.addEventListener("ShowToolTip", function(event) {
  console.log("ShowToolTip=" + event.detail);
  self.port.emit("ShowToolTip", event.detail);
  
}, false);
