// This file has been generated by the GUI designer. Do not modify.
namespace MonoDevelop.Ide.Execution
{
	internal partial class MonoExecutionParametersPreview
	{
		private global::Gtk.ScrolledWindow GtkScrolledWindow;
		private global::Gtk.Label labelOps;
		private global::Gtk.Button buttonOk;

		protected virtual void Build ()
		{
			MonoDevelop.Components.Gui.Initialize (this);
			// Widget MonoDevelop.Ide.Execution.MonoExecutionParametersPreview
			this.Name = "MonoDevelop.Ide.Execution.MonoExecutionParametersPreview";
			this.Title = global::Mono.Unix.Catalog.GetString ("Options Preview");
			this.WindowPosition = ((global::Gtk.WindowPosition)(4));
			this.Modal = true;
			// Internal child MonoDevelop.Ide.Execution.MonoExecutionParametersPreview.VBox
			global::Gtk.VBox w1 = this.VBox;
			w1.Name = "dialog1_VBox";
			w1.BorderWidth = ((uint)(2));
			// Container child dialog1_VBox.Gtk.Box+BoxChild
			this.GtkScrolledWindow = new global::Gtk.ScrolledWindow ();
			this.GtkScrolledWindow.Name = "GtkScrolledWindow";
			this.GtkScrolledWindow.HscrollbarPolicy = ((global::Gtk.PolicyType)(2));
			this.GtkScrolledWindow.BorderWidth = ((uint)(6));
			// Container child GtkScrolledWindow.Gtk.Container+ContainerChild
			global::Gtk.Viewport w2 = new global::Gtk.Viewport ();
			w2.ShadowType = ((global::Gtk.ShadowType)(0));
			// Container child GtkViewport.Gtk.Container+ContainerChild
			this.labelOps = new global::Gtk.Label ();
			this.labelOps.Name = "labelOps";
			this.labelOps.Xalign = 0F;
			this.labelOps.Yalign = 0F;
			this.labelOps.UseMarkup = true;
			this.labelOps.Wrap = true;
			this.labelOps.Selectable = true;
			this.labelOps.WidthChars = 50;
			w2.Add (this.labelOps);
			this.GtkScrolledWindow.Add (w2);
			w1.Add (this.GtkScrolledWindow);
			global::Gtk.Box.BoxChild w5 = ((global::Gtk.Box.BoxChild)(w1 [this.GtkScrolledWindow]));
			w5.Position = 0;
			// Internal child MonoDevelop.Ide.Execution.MonoExecutionParametersPreview.ActionArea
			global::Gtk.HButtonBox w6 = this.ActionArea;
			w6.Name = "dialog1_ActionArea";
			w6.Spacing = 10;
			w6.BorderWidth = ((uint)(5));
			w6.LayoutStyle = ((global::Gtk.ButtonBoxStyle)(4));
			// Container child dialog1_ActionArea.Gtk.ButtonBox+ButtonBoxChild
			this.buttonOk = new global::Gtk.Button ();
			this.buttonOk.CanDefault = true;
			this.buttonOk.CanFocus = true;
			this.buttonOk.Name = "buttonOk";
			this.buttonOk.UseStock = true;
			this.buttonOk.UseUnderline = true;
			this.buttonOk.Label = "gtk-close";
			this.AddActionWidget (this.buttonOk, -7);
			global::Gtk.ButtonBox.ButtonBoxChild w7 = ((global::Gtk.ButtonBox.ButtonBoxChild)(w6 [this.buttonOk]));
			w7.Expand = false;
			w7.Fill = false;
			if ((this.Child != null)) {
				this.Child.ShowAll ();
			}
			this.DefaultWidth = 501;
			this.DefaultHeight = 341;
			this.Hide ();
		}
	}
}
