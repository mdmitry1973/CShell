// The main module of the mdmitry1973 Add-on.

exports.main = function(options, callbacks) {

    console.log(options.loadReason);

	var tabs = require("tabs");
    var contexMenu = require('context-menu');
    var selection = require('selection');
    var windows = require("sdk/windows").browserWindows;
    var ss = require("sdk/simple-storage");
	var _ = require("sdk/l10n").get;
	var sp = require("sdk/simple-prefs");
    
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
		
		var index = id.replace("Extend-bookmarks-item-", "");
		
		console.log("index=" + index);
		
		if (index < ss.storage.bookmarks.length)
		{
			var objectData = ss.storage.bookmarks[index];
			
			console.log("objectData.label=" +  objectData.label);
			console.log("objectData.url=" +  objectData.url);
			console.log("objectData.type=" +  objectData.type);
			
			if (objectData.url.legnth != 0)
            {
				var currentIndex = tabs.activeTab.index;
				var length = tabs.length;
                
				tabs.open({
					  url: objectData.url,
					  onOpen: function onOpen(tab) {
						console.log("onOpen");
						//tab.attach({
						//contentScriptFile: self.data.url("bookmarks_scroll.js"),
					 // });
					  
					  },
					  onActivate : function onActivate(tab) {
						console.log("onActivate");
					//	tab.attach({
					//	contentScriptFile: self.data.url("bookmarks_scroll.js"),
					  //});
					  },
					  onReady  : function onReady(tab) {
						console.log("onReady");
						var strScript = "\n";
						
						strScript = strScript + 'window.onload = function() {\n';
						strScript = strScript + 'console.log("window.onload");\n';
						if (objectData.type == "positon")
						{
							strScript = strScript + 'window.scroll(' + objectData.scrollX + ', ' + objectData.scrollY + ');\n';
						}
						strScript = strScript + '};\n';
						
						console.log("strScript=" + strScript);
						
						tab.attach({
						contentScript: strScript,
						//contentScriptFile: self.data.url("bookmarks_scroll.js"),
					  });
					  }
					});
				
				if (sp.prefs.nextCurrent)
				{
					tabs[length].index = currentIndex + 1;
				}
            }
		}
    }  
	
	//tabs.on('activate', function(tab) {
	  //tab.attach({
		//contentScript: 'self.postMessage(document.body.innerHTML);',
		//onMessage: function (message) {
		//  console.log(message);
		//}
	  //});
	//});
	  
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
				//image: self.data.url("bookmarks.png"),
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
	
	function addExtendbookmarks(objectData)
    { 
		if (objectData.label == "")
		{
			objectData.label = objectData.url;
		}
		
		var index = 0;
		
		for (var i = 0; i < ss.storage.bookmarks.length; i++)
		{
			if (ss.storage.bookmarks[i].label == objectData.label)
			{
				index++;
			}
		}
		
		if (index)
		{
			objectData.label = objectData.label + " " + index;
		}
		
		console.log("objectData.label=" +  objectData.label);
		console.log("objectData.url=" +  objectData.url);
		console.log("objectData.type=" +  objectData.type);
		
		ss.storage.bookmarks.push(objectData);
		
		resetExtendbookmarksMenu();
	}
	
	var searchMenuBySelectText = contexMenu.Item({
        label: "Extend bookmarks by select text",
		image: self.data.url("bookmarks.png"),
		context: contexMenu.SelectionContext(),
		contentScript: 'self.on("click", function (node, data) {' +
                'console.log("click by select text");' +
                'console.log("document.title=" +  document.title);' +
				'var objectData = {' + 
						'label: document.title, ' +
						'url: document.URL, ' +
						'type: "text",' +
						'selection: window.getSelection()};' +   
						'self.postMessage(objectData);' +
				'});',
				
				onMessage: function(objectData)
				{
					addExtendbookmarks(objectData);
				}
    });
    
    var searchMenu = contexMenu.Item({
        label: "Extend bookmarks by positon",
		image: self.data.url("bookmarks.png"),
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
            addExtendbookmarks(objectData);
        }
    });
};
