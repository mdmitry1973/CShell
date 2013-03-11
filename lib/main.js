// The main module of the mdmitry1973 Add-on.

exports.main = function(options, callbacks) {

    console.log(options.loadReason);

	var tabs = require("tabs");
    var contexMenu = require('context-menu');
    var ss = require("sdk/simple-storage");
	var _ = require("sdk/l10n").get;
	var sp = require("sdk/simple-prefs");
	var self = require("sdk/self");
	var notifications = require("sdk/notifications");
    
    //create empty urls store
    if (!ss.storage.bookmarks)
    {
        console.log("empty bookmarks");
        ss.storage.bookmarks = [];
    }
	
	//ss.storage.bookmarks = [];
	
	//add Advanced-bookmarks menu in bookmarks menu
	
	var menusep =require("menuitems").Menuitem({
		id: "Advanced-bookmarks-sep",
		menuid: "bookmarksMenuPopup",
		menuItemType: "menuseparator",
		label: "Advanced menuseparator",
		className: 'pizazz',
		disabled: false,
		checked: false,
	  });
	  
	  
	  
	  //bookmarksToolbarFolderMenu 
	  //organizeBookmarksSeparator 
	  //unsortedBookmarks 
	 // bookmarksShowAll
	  //iewBookmarksToolbar
	  //BMB_bookmarksPopup done
	  //personal-bookmarks done
	  //appmenu_bookmarkThisPage
	  //appmenu_bookmarksToolbar
	  
	 
	
	var menubookmaks = require("menuitems").Menuitem({
		id: "Advanced-bookmarks-Menu",
		menuid: "bookmarksMenuPopup",
		menuItemType: "menu",
		label: _("Advanced bookmarks"),
		image: self.data.url("bookmarks.png"),
		className: 'pizazz',
		disabled: false,
		checked: false,
	});
	  
	var menubookmaksmenupopupItem = require("menuitems").Menuitem({
		id: "Advanced-bookmarks-menupopup",
		menuid: "Advanced-bookmarks-Menu",
		label: "Advanced bookmaks item",
		menuItemType: "menupopup",
		className: 'pizazz',
		disabled: false,
		checked: false,
	});
	
	//second bookmarks menu
	
	var menusep2 =require("menuitems").Menuitem({
		id: "Advanced-bookmarks-sep-2",
		menuid: "BMB_bookmarksPopup",
		label: "Advanced menuseparator",
		menuItemType: "menuseparator",
		className: 'pizazz',
		disabled: false,
		checked: false,
	  });
	  
	var menubookmaks2 = require("menuitems").Menuitem({
		id: "Advanced-bookmarks-Menu-2",
		menuid: "BMB_bookmarksPopup",
		menuItemType: "menu",
		label: _("Advanced bookmarks"),
		image: self.data.url("bookmarks.png"),
		className: 'pizazz',
		disabled: false,
		checked: false,
	});
	  
	var menubookmaksmenupopupItem2 = require("menuitems").Menuitem({
		id: "Advanced-bookmarks-menupopup-2",
		menuid: "Advanced-bookmarks-Menu-2",
		label: "Advanced bookmaks item",
		menuItemType: "menupopup",
		className: 'pizazz',
		disabled: false,
		checked: false,
	});
	
	//third bookmarks menu
	  
	var menusep3 =require("menuitems").Menuitem({
		id: "Advanced-bookmarks-sep-3",
		menuid: "appmenu_bookmarksPopup",
		label: "Advanced menuseparator",
		menuItemType: "menuseparator",
		className: 'pizazz',
		disabled: false,
		checked: false,
	  });
	  
	var menubookmaks3 = require("menuitems").Menuitem({
		id: "Advanced-bookmarks-Menu-3",
		menuid: "appmenu_bookmarksPopup",
		menuItemType: "menu",
		label: _("Advanced bookmarks"),
		image: self.data.url("bookmarks.png"),
		className: 'pizazz',
		disabled: false,
		checked: false,
	});
	  
	var menubookmaksmenupopupItem3 = require("menuitems").Menuitem({
		id: "Advanced-bookmarks-menupopup-3",
		menuid: "Advanced-bookmarks-Menu-3",
		label: "Advanced bookmaks item",
		menuItemType: "menupopup",
		className: 'pizazz',
		disabled: false,
		checked: false,
	});
	
	//select BookMarksManger
	function itemBookMarksManger(id)
    {
		var panel = require("sdk/panel").Panel({
                height: 400,
                width: 600,
                contentURL: require("sdk/self").data.url("BookmarksManager.html"),
                contentScriptFile: require("sdk/self").data.url("BookmarksManager.js")
            });
			
		panel.port.on("RequesBookMarks", function(text) {
				//console.log("port.on RequesBookMarks=" + text);
                
				var jsObject = JSON.parse(text);
				var arrLocalizeStrings = [];
			
				for (var i = 0; i < jsObject.length; i++)
				{
					console.log("jsObject[i]=" + jsObject[i]);
				   var new_text = _(jsObject[i]);
				   console.log("new_text=" + new_text);
				   arrLocalizeStrings.push(new_text);
				}
                
				var message = { bookmarks:   ss.storage.bookmarks,  
                            arrLocalizeStrings:   arrLocalizeStrings
				};
        
                var jsonString = JSON.stringify(message);
                panel.port.emit("SendBookMarks", jsonString);
        });
        
         panel.port.on("StoreData", function(text) {
            //console.log("port.on StoreData=" + text);
            
            ss.storage.bookmarks = [];
            
            var jsObject = JSON.parse(text);
        
            for (var i = 0; i < jsObject.length; i++)
            {
                ss.storage.bookmarks.push(jsObject[i]);
            }
            
            resetAdvancedbookmarksMenu();
        });
        
        panel.port.on("ShowToolTip", function(text) {
            //console.log("port.on ShowToolTip=" + text);
            
            notifications.notify({
                        text: text
                });
        });
		
        panel.show();
	}
	
	//select bookmark
	function itemAction(id)
    {    
        console.log("itemAction=" + id);
		
		var index = id.replace("Advanced-bookmarks-item-", "");
		
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
						
						if (objectData.type == "positon")
						{
							var strScript = "\n";
							
							strScript = strScript + 'window.onload = function() {\n';
							strScript = strScript + 'console.log("window.onload");\n';
							strScript = strScript + 'window.scroll(' + objectData.scrollX + ', ' + objectData.scrollY + ');\n';
							strScript = strScript + '};\n';
							
							console.log("strScript=" + strScript);
							
							tab.attach({
								contentScript: strScript,
								//contentScriptFile: self.data.url("bookmarks_scroll.js"),
							});
						}
						else
						{
							console.log("objectData.selection=" + objectData.selection);
							//selection.text = objectData.selection;
							
							var strScript = "\n";
							
							strScript = strScript + 'window.onload = function() {\n';
							strScript = strScript + 'console.log("window.onload");\n';
							//strScript = strScript + 'window.scroll(' + objectData.scrollX + ', ' + objectData.scrollY + ');\n';
							strScript = strScript + 'window.find("' + objectData.selection + '", true, false, false, true, true, false);\n';
							strScript = strScript + '};\n';
							
							console.log("strScript=" + strScript);
							
							var worker = tab.attach({
								contentScript: strScript,
								//contentScriptFile: self.data.url("bookmarks_scroll.js"),
							});
							
							//worker.port.on('iniWindow', function(tab) {
							//	  console.log(' worker iniWindow ');
							//	});
						}
					  }
					});
				
				if (sp.prefs.nextCurrent)
				{
					tabs[length].index = currentIndex + 1;
				}
				
				
            }
		}
    }  
	  
	function resetAdvancedbookmarksMenu()
    { 
		menubookmaksmenupopupItem.destroy();
		menubookmaksmenupopupItem2.destroy();
		menubookmaksmenupopupItem3.destroy();
		
		menubookmaksmenupopupItem = require("menuitems").Menuitem({
			id: "Advanced-bookmarks-menupopup",
			menuid: "Advanced-bookmarks-Menu",
			label: "Advanced bookmaks item",
			menuItemType: "menupopup",
			className: 'pizazz',
			disabled: false,
			checked: false,
		});
		
		menubookmaksmenupopupItem2 = require("menuitems").Menuitem({
			id: "Advanced-bookmarks-menupopup-2",
			menuid: "Advanced-bookmarks-Menu-2",
			label: "Advanced bookmaks item",
			menuItemType: "menupopup",
			className: 'pizazz',
			disabled: false,
			checked: false,
		});
		
		menubookmaksmenupopupItem3 = require("menuitems").Menuitem({
			id: "Advanced-bookmarks-menupopup-3",
			menuid: "Advanced-bookmarks-Menu-3",
			label: "Advanced bookmaks item",
			menuItemType: "menupopup",
			className: 'pizazz',
			disabled: false,
			checked: false,
		});
		
		var menuBookmaksMangerItem = require("menuitems").Menuitem({
				id: "BookmaksManger",
				menuid: "Advanced-bookmarks-menupopup",
				label: _("Bookmarks Manger"),
				className: 'pizazz',
				disabled: false,
				checked: false,
				onCommand: function() {
					itemBookMarksManger();
				}
			 });
			 
		menuBookmaksMangerItem = require("menuitems").Menuitem({
				id: "BookmaksManger-2",
				menuid: "Advanced-bookmarks-menupopup-2",
				label: _("Bookmarks Manger"),
				className: 'pizazz',
				disabled: false,
				checked: false,
				onCommand: function() {
					itemBookMarksManger();
				}
			 });
		
		for (var i = 0; i < ss.storage.bookmarks.length; i++)
		{
			var menubookmaksItem = require("menuitems").Menuitem({
				id: "Advanced-bookmarks-item-" + i,
				menuid: "Advanced-bookmarks-menupopup",
				label: ss.storage.bookmarks[i].label,
				className: 'pizazz',
				disabled: false,
				checked: false,
				onCommand: function(data) {
					console.log("data=" +  data.id);
					itemAction(data.id);
				}
			 });
			 
			var menubookmaksItem2 = require("menuitems").Menuitem({
				id: "Advanced-bookmarks-item-" + i,
				menuid: "Advanced-bookmarks-menupopup-2",
				label: ss.storage.bookmarks[i].label,
				className: 'pizazz',
				disabled: false,
				checked: false,
				onCommand: function(data) {
					console.log("data=" +  data.id);
					itemAction(data.id);
				}
			 });
			 
			var menubookmaksItem3 = require("menuitems").Menuitem({
				id: "Advanced-bookmarks-item-" + i,
				menuid: "Advanced-bookmarks-menupopup-3",
				label: ss.storage.bookmarks[i].label,
				className: 'pizazz',
				disabled: false,
				checked: false,
				onCommand: function(data) {
					console.log("data=" +  data.id);
					itemAction(data.id);
				}
			 });
		}
	}
	
	resetAdvancedbookmarksMenu();
	
	function addAdvancedbookmarks(objectData)
    { 
		if (objectData.label == "")
		{
			objectData.label = objectData.url;
		}
		
		var index = 0;
		
		for (var i = 0; i < ss.storage.bookmarks.length; i++)
		{
			//console.log("ss.storage.bookmarks[i].label=" +  ss.storage.bookmarks[i].label);
			
			if (index ==0 &&
				ss.storage.bookmarks[i].label == objectData.label)
			{
				console.log("index found=" +  index);
				index++;
				i = -1;
			}
			else
			if (ss.storage.bookmarks[i].label == (objectData.label + " " + index))
			{
				console.log("index found=" +  index);
				index++;
				i = -1;
			}
		}
		
		if (index)
		{
			objectData.label = objectData.label + " " + index;
		}
		
		console.log("index=" +  index);
		console.log("objectData.label=" +  objectData.label);
		console.log("objectData.url=" +  objectData.url);
		console.log("objectData.type=" +  objectData.type);
		
		ss.storage.bookmarks.push(objectData);
		
		resetAdvancedbookmarksMenu();
	}
	
	//action for text context menu
	var searchMenuBySelectText = contexMenu.Item({
        label: _("Advanced bookmarks by select text"),
		image: self.data.url("bookmarks.png"),
		context: contexMenu.SelectionContext(),
		contentScript: 'self.on("click", function (node, data) {' +
                'console.log("click by select text");' +
                'console.log("document.title=" +  document.title);' +
				'var objectData = {' + 
						'label: document.title, ' +
						'url: document.URL, ' +
						'type: "text",' +
						'selection: window.getSelection().toString()};' +   
						'self.postMessage(objectData);' +
				'});',
				
				onMessage: function(objectData)
				{
					addAdvancedbookmarks(objectData);
				}
    });
    
	//action for position context menu
    var searchMenu = contexMenu.Item({
        label: _("Advanced bookmarks by positon"),
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
            addAdvancedbookmarks(objectData);
        }
    });
};
