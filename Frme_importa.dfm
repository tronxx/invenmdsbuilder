object Frame_importa: TFrame_importa
  Left = 0
  Top = 0
  Width = 610
  Height = 299
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 610
    Height = 299
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object PageControl1: TPageControl
      Left = 0
      Top = 0
      Width = 610
      Height = 299
      ActivePage = TabSheet1
      Align = alClient
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = 'Datos a Importar'
        object sgrd_datos: TAdvStringGrid
          Left = 0
          Top = 47
          Width = 602
          Height = 224
          Align = alClient
          ColCount = 5
          DefaultRowHeight = 21
          FixedCols = 1
          RowCount = 5
          FixedRows = 1
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goRowMoving, goColMoving, goRowSelect]
          TabOrder = 0
          Bands.Active = False
          Bands.PrimaryColor = clInfoBk
          Bands.PrimaryLength = 1
          Bands.SecondaryColor = clWindow
          Bands.SecondaryLength = 1
          Bands.Print = False
          AutoNumAlign = False
          AutoSize = False
          VAlignment = vtaTop
          EnhTextSize = False
          EnhRowColMove = False
          SortFixedCols = False
          SortNormalCellsOnly = False
          SizeWithForm = False
          Multilinecells = False
          SortDirection = sdAscending
          SortFull = True
          SortAutoFormat = True
          SortShow = False
          SortIndexShow = False
          EnableGraphics = False
          EnableHTML = True
          EnableWheel = True
          Flat = False
          SortColumn = 0
          HintColor = clYellow
          SelectionColor = clHighlight
          SelectionTextColor = clHighlightText
          SelectionRectangle = False
          SelectionRTFKeep = False
          HintShowCells = False
          HintShowLargeText = False
          OleAcceptFiles = True
          OleAcceptText = True
          PrintSettings.FooterSize = 0
          PrintSettings.HeaderSize = 0
          PrintSettings.Time = ppNone
          PrintSettings.Date = ppNone
          PrintSettings.DateFormat = 'dd/mm/yyyy'
          PrintSettings.PageNr = ppNone
          PrintSettings.Title = ppNone
          PrintSettings.Font.Charset = DEFAULT_CHARSET
          PrintSettings.Font.Color = clWindowText
          PrintSettings.Font.Height = -11
          PrintSettings.Font.Name = 'MS Sans Serif'
          PrintSettings.Font.Style = []
          PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
          PrintSettings.HeaderFont.Color = clWindowText
          PrintSettings.HeaderFont.Height = -11
          PrintSettings.HeaderFont.Name = 'MS Sans Serif'
          PrintSettings.HeaderFont.Style = []
          PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
          PrintSettings.FooterFont.Color = clWindowText
          PrintSettings.FooterFont.Height = -11
          PrintSettings.FooterFont.Name = 'MS Sans Serif'
          PrintSettings.FooterFont.Style = []
          PrintSettings.Borders = pbNoborder
          PrintSettings.BorderStyle = psSolid
          PrintSettings.Centered = False
          PrintSettings.RepeatFixedRows = False
          PrintSettings.RepeatFixedCols = False
          PrintSettings.LeftSize = 0
          PrintSettings.RightSize = 0
          PrintSettings.ColumnSpacing = 0
          PrintSettings.RowSpacing = 0
          PrintSettings.TitleSpacing = 0
          PrintSettings.Orientation = poPortrait
          PrintSettings.FixedWidth = 0
          PrintSettings.FixedHeight = 0
          PrintSettings.UseFixedHeight = False
          PrintSettings.UseFixedWidth = False
          PrintSettings.FitToPage = fpNever
          PrintSettings.PageNumSep = '/'
          PrintSettings.NoAutoSize = False
          PrintSettings.PrintGraphics = False
          HTMLSettings.Width = 100
          Navigation.AllowInsertRow = False
          Navigation.AllowDeleteRow = False
          Navigation.AdvanceOnEnter = False
          Navigation.AdvanceInsert = False
          Navigation.AutoGotoWhenSorted = False
          Navigation.AutoGotoIncremental = False
          Navigation.AutoComboDropSize = False
          Navigation.AdvanceDirection = adLeftRight
          Navigation.AllowClipboardShortCuts = False
          Navigation.AllowSmartClipboard = False
          Navigation.AllowRTFClipboard = False
          Navigation.AllowClipboardAlways = False
          Navigation.AllowClipboardRowGrow = True
          Navigation.AllowClipboardColGrow = True
          Navigation.AdvanceAuto = False
          Navigation.InsertPosition = pInsertBefore
          Navigation.CursorWalkEditor = False
          Navigation.MoveRowOnSort = False
          Navigation.ImproveMaskSel = False
          Navigation.AlwaysEdit = False
          Navigation.CopyHTMLTagsToClipboard = True
          Navigation.LineFeedOnEnter = False
          ColumnSize.Save = False
          ColumnSize.Stretch = False
          ColumnSize.Location = clRegistry
          CellNode.Color = clSilver
          CellNode.NodeType = cnFlat
          CellNode.NodeColor = clBlack
          SizeWhileTyping.Height = False
          SizeWhileTyping.Width = False
          MaxEditLength = 0
          MouseActions.AllSelect = False
          MouseActions.ColSelect = False
          MouseActions.RowSelect = False
          MouseActions.DirectEdit = False
          MouseActions.DirectComboDrop = False
          MouseActions.DisjunctRowSelect = False
          MouseActions.AllColumnSize = False
          MouseActions.AllRowSize = False
          MouseActions.CaretPositioning = False
          IntelliPan = ipVertical
          URLColor = clBlue
          URLShow = False
          URLFull = False
          URLEdit = False
          ScrollType = ssNormal
          ScrollColor = clNone
          ScrollWidth = 16
          ScrollSynch = False
          ScrollProportional = False
          ScrollHints = shNone
          OemConvert = False
          FixedFooters = 0
          FixedRightCols = 0
          FixedColWidth = 64
          FixedRowHeight = 21
          FixedFont.Charset = DEFAULT_CHARSET
          FixedFont.Color = clWindowText
          FixedFont.Height = -11
          FixedFont.Name = 'MS Sans Serif'
          FixedFont.Style = []
          FixedAsButtons = False
          FloatFormat = '%.2f'
          WordWrap = False
          ColumnHeaders.Strings = (
            'Col01'
            'Col02')
          Lookup = False
          LookupCaseSensitive = False
          LookupHistory = False
          BackGround.Top = 0
          BackGround.Left = 0
          BackGround.Display = bdTile
          BackGround.Cells = bcNormal
          Filter = <>
          ColWidths = (
            64
            64
            64
            64
            64)
          RowHeights = (
            21
            21
            21
            21
            21)
        end
        object GroupBox1: TGroupBox
          Left = 0
          Top = 0
          Width = 602
          Height = 47
          Align = alTop
          Caption = 'Datos del Archivo'
          TabOrder = 1
          object Label1: TLabel
            Left = 13
            Top = 24
            Width = 39
            Height = 13
            Caption = 'Archivo:'
          end
          object edt_nomarch: TEdit
            Left = 56
            Top = 20
            Width = 361
            Height = 21
            TabOrder = 0
            Text = 'edt_nomarch'
            OnKeyDown = edt_nomarchKeyDown
          end
          object BitBtn1: TBitBtn
            Left = 424
            Top = 16
            Width = 75
            Height = 25
            Action = buscar_archivo
            Caption = 'Buscar'
            TabOrder = 1
            Glyph.Data = {
              36040000424D3604000000000000360000002800000010000000100000000100
              2000000000000004000000000000000000000000000000000000FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF00000000000000000000000000000000000000000000000000000000000000
              00000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
              00000000000000FFFF00BFBFBF0000FFFF00BFBFBF0000FFFF00BFBFBF0000FF
              FF00BFBFBF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF000000
              0000FFFFFF000000000000FFFF00BFBFBF0000FFFF00BFBFBF0000FFFF00BFBF
              BF0000FFFF00BFBFBF0000FFFF0000000000FF00FF00FF00FF00FF00FF000000
              000000FFFF00FFFFFF000000000000FFFF00BFBFBF0000FFFF00BFBFBF0000FF
              FF00BFBFBF0000FFFF00BFBFBF0000FFFF0000000000FF00FF00FF00FF000000
              0000FFFFFF0000FFFF00FFFFFF00000000000000000000000000000000000000
              00000000000000000000000000000000000000000000FF00FF00FF00FF000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
              FF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
              0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
              FF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000
              000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF007F7F7F00000000000000000000000000000000007F7F7F00FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
              FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
          end
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Formato Esperado'
        ImageIndex = 1
        object mmo_formato: TMemo
          Left = 0
          Top = 0
          Width = 602
          Height = 271
          Align = alClient
          Lines.Strings = (
            'mmo_formato')
          TabOrder = 0
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = '*.csv'
    Left = 440
    Top = 56
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 512
    Top = 64
    object buscar_archivo: TAction
      Caption = 'Buscar'
      ImageIndex = 25
      OnExecute = buscar_archivoExecute
    end
  end
end
