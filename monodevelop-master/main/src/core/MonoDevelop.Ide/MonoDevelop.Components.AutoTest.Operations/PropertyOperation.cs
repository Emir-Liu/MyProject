﻿//
// PropertyOperation.cs
//
// Author:
//       iain holmes <iain@xamarin.com>
//
// Copyright (c) 2015 Xamarin, Inc
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
using System.Collections.Generic;

namespace MonoDevelop.Components.AutoTest.Operations
{
	public class PropertyOperation : Operation, IFilterOperation
	{
		internal string PropertyName;
		object DesiredValue;

		public PropertyOperation (string propertyName, object desiredValue)
		{
			PropertyName = propertyName;
			DesiredValue = desiredValue;
		}

		public override List<AppResult> Execute (List<AppResult> resultSet)
		{
			List<AppResult> newResultSet = new List<AppResult> ();

			foreach (var result in resultSet) {
				AppResult newResult = result.Property (PropertyName, DesiredValue);
				if (newResult != null) {
					newResultSet.Add (newResult);
				}
			}

			return newResultSet;
		}

		public AppResult Filter (AppResult result)
		{
			return result.Property (PropertyName, DesiredValue);
		}

		public override string ToString ()
		{
			return string.Format ("Property ({0}, {1})", PropertyName, DesiredValue);
		}
	}
}
