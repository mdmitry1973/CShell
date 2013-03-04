// The main module of the mdmitry1973 Add-on.

exports.main = function(options, callbacks) {

    console.log(options.loadReason);

    var contexMenu = require('context-menu');
    var selection = require('selection');
    var windows = require("sdk/windows").browserWindows;
    var ss = require("sdk/simple-storage");
    
    //create empty urls store
    if (!ss.storage.bookmarks)
    {
        console.log("empty bookmarks");
        ss.storage.bookmarks = [];
    }
	
	ss.storage.bookmarks = [];
	
	var self = require("sdk/self");
	
	var menusep =require("menuitems").Menuitem({
		id: "Extend-bookmarks-sep",
		menuid: "bookmarksMenuPopup",
		menuItemType: "menuseparator",
		label: "Extend menuseparator",
		className: 'pizazz',
		disabled: false,
		checked: false,
	  });
	
	var menubookmaks = require("menuitems").Menuitem({
		id: "Extend-bookmarks-Menu",
		menuid: "bookmarksMenuPopup",
		menuItemType: "menu",
		label: "Extend bookmarks",
		image: self.data.url("bookmarks.png"),
		className: 'pizazz',
		disabled: false,
		checked: false,
	});
	  
	var menubookmaksmenupopupItem = require("menuitems").Menuitem({
		id: "Extend-bookmarks-menupopup",
		menuid: "Extend-bookmarks-Menu",
		label: "Extend bookmaks item",
		menuItemType: "menupopup",
		className: 'pizazz',
		disabled: false,
		checked: false,
	});
	 
	function itemAction(id)
    {    
        console.log("itemAction=" + id);
    }  
	  
	  
	function resetExtendbookmarksMenu()
    { 
		menubookmaksmenupopupItem.destroy();
		
		menubookmaksmenupopupItem = require("menuitems").Menuitem({
			id: "Extend-bookmarks-menupopup",
			menuid: "Extend-bookmarks-Menu",
			label: "Extend bookmaks item",
			menuItemType: "menupopup",
			className: 'pizazz',
			disabled: false,
			checked: false,
		});
		
		for (var i = 0; i < ss.storage.bookmarks.length; i++)
		{
			var menubookmaksItem = require("menuitems").Menuitem({
				id: "Extend-bookmarks-item-" + i,
				menuid: "Extend-bookmarks-menupopup",
				label: ss.storage.bookmarks[i].label,
				image: self.data.url("bookmarks.png"),
				className: 'pizazz',
				disabled: false,
				checked: false,
				onCommand: function() {
					itemAction(menubookmaksItem.id);
				}
			 });
		}
	}
	
	resetExtendbookmarksMenu();
	
	var searchMenuBySelectText = contexMenu.Item({
        label: "Extend bookmarks by select text",
		context: contexMenu.SelectionContext(),
		
		 contentScript: 'self.on("click", function (node, data) {' +
                'console.log("click by select text");' +
                'console.log("document.title=" +  document.title);' +
				//'console.log("document.title=" +  document.title);' +
				'var objectData = {' + 
						'label: document.title, ' +
						'url: document.URL, ' +
						'type: "text",' +
						'selection: window.getSelection()};' +   
						'self.postMessage(objectData);' +
				'});',
				
				onMessage: function(objectData)
				{
					console.log("objectData.label=" +  objectData.label);
					console.log("objectData.url=" +  objectData.url);
					console.log("objectData.type=" +  objectData.type);
					
					ss.storage.bookmarks.push(objectData);
					resetExtendbookmarksMenu();
				}
    });
    
    var searchMenu = contexMenu.Item({//Menu({
        label: "Extend bookmarks by positon",
        context: contexMenu.PageContext(),
        contentScript: 'self.on("click", function (node, data) {' +
                'console.log("click by positon");' +
				'console.log("document.title=" +  document.title);' +
				'console.log("window.scrollX=" +  window.scrollX);' +
				'console.log("window.scrollY=" +  window.scrollY);' +
				'console.log("window.innerHeight=" +  window.innerHeight);' +
				'var objectData = {' + 
						'label: document.title, ' +
						'url: document.URL, ' +
						'scrollX: window.scrollX, ' +
						'scrollY: window.scrollY,' +
						'type: "positon"};' +   
						'self.postMessage(objectData);' +
        '});',
        
        onMessage: function(objectData)
        {
            console.log("objectData.label=" +  objectData.label);
			console.log("objectData.url=" +  objectData.url);
			console.log("objectData.type=" +  objectData.type);
			
			ss.storage.bookmarks.push(objectData);
			
			resetExtendbookmarksMenu();
        }
    });
};
