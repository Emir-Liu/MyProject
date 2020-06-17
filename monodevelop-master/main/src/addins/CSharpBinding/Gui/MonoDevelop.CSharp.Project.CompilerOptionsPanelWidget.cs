
// This file has been generated by the GUI designer. Do not modify.
using MonoDevelop.Ide.Gui;

namespace MonoDevelop.CSharp.Project
{
	partial class CompilerOptionsPanelWidget
	{
		private global::Gtk.VBox vbox1;
		
		private global::Gtk.Label label82;
		
		private global::Gtk.HBox hbox5;
		
		private global::Gtk.Label label76;
		
		private global::Gtk.VBox vbox2;
		
		private global::Gtk.Table table7;
		
		private global::Gtk.ComboBoxEntry codepageEntry;
		
		private global::Gtk.HBox hbox57;
		
		private MonoDevelop.Ide.Gui.OptionPanels.DotNetCompileTargetSelector compileTargetCombo;
		
		private global::MonoDevelop.Components.FileEntry iconEntry;
		
		private global::Gtk.Label label1;
		
		private global::Gtk.Label label3;
		
		private global::Gtk.Label label86;
		
		private global::Gtk.Label label88;
		
		private global::Gtk.ComboBoxEntry mainClassEntry;
		
		private global::Gtk.CheckButton noStdLibCheckButton;
		
		private global::Gtk.Label label83;
		
		private global::Gtk.Label label75;
		
		private global::Gtk.HBox hbox7;
		
		private global::Gtk.Label label74;
		
		private global::Gtk.VBox vbox3;
		
		private global::Gtk.Table table2;

		private MonoDevelop.Components.ImageView langVersionWarningIcon;
		
		private global::Gtk.Label label2;
		
		private global::Gtk.ComboBox langVerCombo;
		
		private global::Gtk.CheckButton allowUnsafeCodeCheckButton;

		protected virtual void Build ()
		{
			MonoDevelop.Components.Gui.Initialize (this);
			// Widget MonoDevelop.CSharp.Project.CompilerOptionsPanelWidget
			MonoDevelop.Components.BinContainer.Attach (this);
			this.Name = "MonoDevelop.CSharp.Project.CompilerOptionsPanelWidget";
			// Container child MonoDevelop.CSharp.Project.CompilerOptionsPanelWidget.Gtk.Container+ContainerChild
			this.vbox1 = new global::Gtk.VBox ();
			this.vbox1.Name = "vbox1";
			this.vbox1.Spacing = 6;
			// Container child vbox1.Gtk.Box+BoxChild
			this.label82 = new global::Gtk.Label ();
			this.label82.Name = "label82";
			this.label82.Xalign = 0F;
			this.label82.LabelProp = global::Mono.Unix.Catalog.GetString ("<b>Code Generation</b>");
			this.label82.UseMarkup = true;
			this.vbox1.Add (this.label82);
			global::Gtk.Box.BoxChild w1 = ((global::Gtk.Box.BoxChild)(this.vbox1 [this.label82]));
			w1.Position = 0;
			w1.Expand = false;
			w1.Fill = false;
			// Container child vbox1.Gtk.Box+BoxChild
			this.hbox5 = new global::Gtk.HBox ();
			this.hbox5.Name = "hbox5";
			this.hbox5.Spacing = 6;
			// Container child hbox5.Gtk.Box+BoxChild
			this.label76 = new global::Gtk.Label ();
			this.label76.WidthRequest = 18;
			this.label76.Name = "label76";
			this.hbox5.Add (this.label76);
			global::Gtk.Box.BoxChild w2 = ((global::Gtk.Box.BoxChild)(this.hbox5 [this.label76]));
			w2.Position = 0;
			w2.Expand = false;
			w2.Fill = false;
			// Container child hbox5.Gtk.Box+BoxChild
			this.vbox2 = new global::Gtk.VBox ();
			this.vbox2.Name = "vbox2";
			this.vbox2.Spacing = 6;
			// Container child vbox2.Gtk.Box+BoxChild
			this.table7 = new global::Gtk.Table (((uint)(5)), ((uint)(2)), false);
			this.table7.Name = "table7";
			this.table7.RowSpacing = ((uint)(6));
			this.table7.ColumnSpacing = ((uint)(6));
			// Container child table7.Gtk.Table+TableChild
			this.codepageEntry = global::Gtk.ComboBoxEntry.NewText ();
			this.codepageEntry.Name = "codepageEntry";
			this.table7.Add (this.codepageEntry);
			global::Gtk.Table.TableChild w3 = ((global::Gtk.Table.TableChild)(this.table7 [this.codepageEntry]));
			w3.TopAttach = ((uint)(3));
			w3.BottomAttach = ((uint)(4));
			w3.LeftAttach = ((uint)(1));
			w3.RightAttach = ((uint)(2));
			w3.XOptions = ((global::Gtk.AttachOptions)(4));
			w3.YOptions = ((global::Gtk.AttachOptions)(4));
			// Container child table7.Gtk.Table+TableChild
			this.hbox57 = new global::Gtk.HBox ();
			this.hbox57.Name = "hbox57";
			// Container child hbox57.Gtk.Box+BoxChild
			this.compileTargetCombo = new MonoDevelop.Ide.Gui.OptionPanels.DotNetCompileTargetSelector();
			this.compileTargetCombo.Name = "compileTargetCombo";
			this.hbox57.Add (this.compileTargetCombo);
			global::Gtk.Box.BoxChild w4 = ((global::Gtk.Box.BoxChild)(this.hbox57 [this.compileTargetCombo]));
			w4.Position = 0;
			w4.Expand = false;
			w4.Fill = false;
			this.table7.Add (this.hbox57);
			global::Gtk.Table.TableChild w5 = ((global::Gtk.Table.TableChild)(this.table7 [this.hbox57]));
			w5.LeftAttach = ((uint)(1));
			w5.RightAttach = ((uint)(2));
			w5.XOptions = ((global::Gtk.AttachOptions)(4));
			w5.YOptions = ((global::Gtk.AttachOptions)(4));
			// Container child table7.Gtk.Table+TableChild
			this.iconEntry = new global::MonoDevelop.Components.FileEntry ();
			this.iconEntry.Name = "iconEntry";
			this.iconEntry.DisplayAsRelativePath = false;
			this.table7.Add (this.iconEntry);
			global::Gtk.Table.TableChild w6 = ((global::Gtk.Table.TableChild)(this.table7 [this.iconEntry]));
			w6.TopAttach = ((uint)(2));
			w6.BottomAttach = ((uint)(3));
			w6.LeftAttach = ((uint)(1));
			w6.RightAttach = ((uint)(2));
			w6.YOptions = ((global::Gtk.AttachOptions)(4));
			// Container child table7.Gtk.Table+TableChild
			this.label1 = new global::Gtk.Label ();
			this.label1.Name = "label1";
			this.label1.Xalign = 0F;
			this.label1.LabelProp = global::Mono.Unix.Catalog.GetString ("Compiler Code Page:");
			this.table7.Add (this.label1);
			global::Gtk.Table.TableChild w7 = ((global::Gtk.Table.TableChild)(this.table7 [this.label1]));
			w7.TopAttach = ((uint)(3));
			w7.BottomAttach = ((uint)(4));
			w7.XOptions = ((global::Gtk.AttachOptions)(4));
			w7.YOptions = ((global::Gtk.AttachOptions)(4));
			// Container child table7.Gtk.Table+TableChild
			this.label3 = new global::Gtk.Label ();
			this.label3.Name = "label3";
			this.label3.Xalign = 0F;
			this.label3.LabelProp = global::Mono.Unix.Catalog.GetString ("Win32 Icon:");
			this.table7.Add (this.label3);
			global::Gtk.Table.TableChild w8 = ((global::Gtk.Table.TableChild)(this.table7 [this.label3]));
			w8.TopAttach = ((uint)(2));
			w8.BottomAttach = ((uint)(3));
			w8.XOptions = ((global::Gtk.AttachOptions)(4));
			w8.YOptions = ((global::Gtk.AttachOptions)(4));
			// Container child table7.Gtk.Table+TableChild
			this.label86 = new global::Gtk.Label ();
			this.label86.Name = "label86";
			this.label86.Xalign = 0F;
			this.label86.LabelProp = global::Mono.Unix.Catalog.GetString ("Compile _Target:");
			this.label86.UseUnderline = true;
			this.table7.Add (this.label86);
			global::Gtk.Table.TableChild w9 = ((global::Gtk.Table.TableChild)(this.table7 [this.label86]));
			w9.XOptions = ((global::Gtk.AttachOptions)(4));
			w9.YOptions = ((global::Gtk.AttachOptions)(0));
			// Container child table7.Gtk.Table+TableChild
			this.label88 = new global::Gtk.Label ();
			this.label88.Name = "label88";
			this.label88.Xalign = 0F;
			this.label88.LabelProp = global::Mono.Unix.Catalog.GetString ("_Main Class:");
			this.label88.UseUnderline = true;
			this.table7.Add (this.label88);
			global::Gtk.Table.TableChild w10 = ((global::Gtk.Table.TableChild)(this.table7 [this.label88]));
			w10.TopAttach = ((uint)(1));
			w10.BottomAttach = ((uint)(2));
			w10.XOptions = ((global::Gtk.AttachOptions)(4));
			w10.YOptions = ((global::Gtk.AttachOptions)(0));
			// Container child table7.Gtk.Table+TableChild
			this.mainClassEntry = new global::Gtk.ComboBoxEntry ();
			this.mainClassEntry.Name = "mainClassEntry";
			this.table7.Add (this.mainClassEntry);
			global::Gtk.Table.TableChild w11 = ((global::Gtk.Table.TableChild)(this.table7 [this.mainClassEntry]));
			w11.TopAttach = ((uint)(1));
			w11.BottomAttach = ((uint)(2));
			w11.LeftAttach = ((uint)(1));
			w11.RightAttach = ((uint)(2));
			w11.YOptions = ((global::Gtk.AttachOptions)(4));
			this.vbox2.Add (this.table7);
			global::Gtk.Box.BoxChild w12 = ((global::Gtk.Box.BoxChild)(this.vbox2 [this.table7]));
			w12.Position = 0;
			// Container child vbox2.Gtk.Box+BoxChild
			this.noStdLibCheckButton = new global::Gtk.CheckButton ();
			this.noStdLibCheckButton.CanFocus = true;
			this.noStdLibCheckButton.Name = "noStdLibCheckButton";
			this.noStdLibCheckButton.Label = global::Mono.Unix.Catalog.GetString ("Do not reference mscorlib.dll");
			this.noStdLibCheckButton.DrawIndicator = true;
			this.noStdLibCheckButton.UseUnderline = true;
			this.vbox2.Add (this.noStdLibCheckButton);
			global::Gtk.Box.BoxChild w13 = ((global::Gtk.Box.BoxChild)(this.vbox2 [this.noStdLibCheckButton]));
			w13.Position = 1;
			w13.Expand = false;
			w13.Fill = false;
			this.hbox5.Add (this.vbox2);
			global::Gtk.Box.BoxChild w14 = ((global::Gtk.Box.BoxChild)(this.hbox5 [this.vbox2]));
			w14.Position = 1;
			this.vbox1.Add (this.hbox5);
			global::Gtk.Box.BoxChild w15 = ((global::Gtk.Box.BoxChild)(this.vbox1 [this.hbox5]));
			w15.Position = 1;
			w15.Expand = false;
			// Container child vbox1.Gtk.Box+BoxChild
			this.label83 = new global::Gtk.Label ();
			this.label83.Name = "label83";
			this.label83.Xalign = 0F;
			this.label83.LabelProp = global::Mono.Unix.Catalog.GetString ("<b>Language Options</b>");
			this.label83.UseMarkup = true;
			this.vbox1.Add (this.label83);
			global::Gtk.Box.BoxChild w16 = ((global::Gtk.Box.BoxChild)(this.vbox1 [this.label83]));
			w16.Position = 2;
			w16.Expand = false;
			w16.Fill = false;
			// Container child vbox1.Gtk.Box+BoxChild
			this.label75 = new global::Gtk.Label ();
			this.label75.WidthRequest = 18;
			this.label75.Name = "label75";
			this.vbox1.Add (this.label75);
			global::Gtk.Box.BoxChild w17 = ((global::Gtk.Box.BoxChild)(this.vbox1 [this.label75]));
			w17.PackType = ((global::Gtk.PackType)(1));
			w17.Position = 3;
			// Container child vbox1.Gtk.Box+BoxChild
			this.hbox7 = new global::Gtk.HBox ();
			this.hbox7.Name = "hbox7";
			this.hbox7.Spacing = 6;
			// Container child hbox7.Gtk.Box+BoxChild
			this.label74 = new global::Gtk.Label ();
			this.label74.WidthRequest = 18;
			this.label74.Name = "label74";
			this.hbox7.Add (this.label74);
			global::Gtk.Box.BoxChild w18 = ((global::Gtk.Box.BoxChild)(this.hbox7 [this.label74]));
			w18.Position = 0;
			w18.Expand = false;
			w18.Fill = false;
			// Container child hbox7.Gtk.Box+BoxChild
			this.vbox3 = new global::Gtk.VBox ();
			this.vbox3.Name = "vbox3";
			this.vbox3.Spacing = 6;
			// Container child vbox3.Gtk.Box+BoxChild
			this.table2 = new global::Gtk.Table (((uint)(1)), ((uint)(2)), false);
			this.table2.Name = "table2";
			this.table2.RowSpacing = ((uint)(6));
			this.table2.ColumnSpacing = ((uint)(6));
			// Container child table2.Gtk.Table+TableChild
			this.langVersionWarningIcon = new MonoDevelop.Components.ImageView (Stock.Warning, Gtk.IconSize.Menu);
			this.langVersionWarningIcon.Visible = false;
			var langVersionHbox = new global::Gtk.HBox (false, 0);
			langVersionHbox.Name = "langVersionHbox";
			langVersionHbox.PackStart (this.langVersionWarningIcon, false, false, 0);
			this.label2 = new global::Gtk.Label ();
			this.label2.Name = "label2";
			this.label2.Xalign = 0F;
			this.label2.LabelProp = global::Mono.Unix.Catalog.GetString ("C# Language Version:");
			langVersionHbox.PackStart (this.label2, false, false, 6);
			this.table2.Add (langVersionHbox);
			global::Gtk.Table.TableChild w19 = ((global::Gtk.Table.TableChild)(this.table2 [langVersionHbox]));
			w19.XOptions = ((global::Gtk.AttachOptions)(4));
			w19.YOptions = ((global::Gtk.AttachOptions)(4));
			w19.XPadding = 6;
			// Container child table2.Gtk.Table+TableChild
			this.langVerCombo = global::Gtk.ComboBox.NewText ();
			this.langVerCombo.Name = "langVerCombo";
			this.table2.Add (this.langVerCombo);
			global::Gtk.Table.TableChild w20 = ((global::Gtk.Table.TableChild)(this.table2 [this.langVerCombo]));
			w20.LeftAttach = ((uint)(1));
			w20.RightAttach = ((uint)(2));
			w20.XOptions = ((global::Gtk.AttachOptions)(4));
			w20.YOptions = ((global::Gtk.AttachOptions)(4));
			this.vbox3.Add (this.table2);
			global::Gtk.Box.BoxChild w21 = ((global::Gtk.Box.BoxChild)(this.vbox3 [this.table2]));
			w21.Position = 0;
			w21.Fill = false;
			// Container child vbox3.Gtk.Box+BoxChild
			this.allowUnsafeCodeCheckButton = new global::Gtk.CheckButton ();
			this.allowUnsafeCodeCheckButton.CanFocus = true;
			this.allowUnsafeCodeCheckButton.Name = "allowUnsafeCodeCheckButton";
			this.allowUnsafeCodeCheckButton.Label = global::Mono.Unix.Catalog.GetString ("Allow '_unsafe' code");
			this.allowUnsafeCodeCheckButton.Active = true;
			this.allowUnsafeCodeCheckButton.DrawIndicator = true;
			this.allowUnsafeCodeCheckButton.UseUnderline = true;
			this.vbox3.Add (this.allowUnsafeCodeCheckButton);
			global::Gtk.Box.BoxChild w22 = ((global::Gtk.Box.BoxChild)(this.vbox3 [this.allowUnsafeCodeCheckButton]));
			w22.Position = 1;
			w22.Expand = false;
			w22.Fill = false;
			this.hbox7.Add (this.vbox3);
			global::Gtk.Box.BoxChild w23 = ((global::Gtk.Box.BoxChild)(this.hbox7 [this.vbox3]));
			w23.Position = 1;
			this.vbox1.Add (this.hbox7);
			global::Gtk.Box.BoxChild w24 = ((global::Gtk.Box.BoxChild)(this.vbox1 [this.hbox7]));
			w24.PackType = ((global::Gtk.PackType)(1));
			w24.Position = 4;
			w24.Expand = false;
			w24.Fill = false;
			this.Add (this.vbox1);
			if ((this.Child != null)) {
				this.Child.ShowAll ();
			}
			this.label88.MnemonicWidget = this.mainClassEntry;
			this.Show ();
		}
	}
}
